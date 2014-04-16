#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <ctype.h>

#include "md5.h"

class BaseClass {
  private:
    unsigned char Buffer[512];
  public:
    BaseClass *next;
    BaseClass *child;
    void SetBuffer(unsigned char *data, int len) {
      memcpy(Buffer, data, len);
    }
    virtual void PrintBuffer() {
      unsigned char *c = Buffer;
      while(*c) {
        if(isalnum(*c)) {
          printf("%c", *c);
        } else {
          printf(".");
        }
        c++;
      }
      printf("\n");
    }
};
class MOOV:public BaseClass {
  void SetBuffer(unsigned char *data, int len) {
    printf("hi!\n");
  }
  void PrintBuffer()
  {
    printf("y0y0\n");
  }
};

class FRNM:public BaseClass {
  public:
    void PrintBuffer() {
      printf("Frame Name: ");
      BaseClass::PrintBuffer();
    }
};

class FRDT:public BaseClass {
  public:
    void PrintBuffer() {
      printf("Frame Data: ");
      BaseClass::PrintBuffer();
    }
};
class Hasherrific {
  private:
    md5_state_t sofar;
    md5_byte_t expected[16];
    bool finished;
    bool matched;
  public:
    Hasherrific()
    {
      md5_init(&sofar);
      finished = false;
      matched = false;
    }

    void Update(unsigned char *data, int len)
    {
      if(finished == false) md5_append(&sofar, data, len);
    }

    void SetExpected(unsigned char *data, int len)
    {
      if(len == 16) {
        memcpy(expected, data, len);
      } else {
        printf("Unexpected hash size.\n");
        exit(EXIT_FAILURE);
      }
    }

    bool Matches()
    {
      if(finished == false) {
        finished = true;
        md5_byte_t tmp[16];
        md5_finish(&sofar, tmp);
        if(memcmp(expected, tmp, 16) == 0) {
          matched = true;
        }
      }
      return matched;
    }
};

class Processor {
  private:
    int fd;
    Hasherrific *hash;
  public:
    Processor()
    {
      hash = new Hasherrific;
      fd = -1;
    }

    ~Processor()
    {
      if(fd != -1) {
        close(fd);
      }
      delete hash;
    }

    void Open(char *filename)
    {
      fd = open(filename, O_RDONLY);
      if(fd == -1) {
        printf("Critical faiure: Failed to open %s: %s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
      }
    }

    void CheckHash()
    {
      unsigned int len;
      unsigned char tag[4];
      unsigned char *buf;
      while(1) {
        if(read(fd, &len, sizeof(unsigned int)) != sizeof(unsigned int)) {
          printf("File is corrupted - hash token not found\n");
          exit(EXIT_FAILURE);
        }

        if(read(fd, tag, 4) != 4) {
          printf("File is corrupted - hash token not found\n");
          exit(EXIT_FAILURE);
        }
        if((memcmp(tag, "HASH", 4) == 0) && (ntohl(len) == 20)) break;
        //printf("%d\n", memcmp(tag, "HASH", 4));
        //printf("got %4s:%d\n", tag, ntohl(len));
        hash->Update((unsigned char *)&len, sizeof(unsigned int));
        hash->Update(tag, 4);
        len = ntohl(len);
        len -= 4;

        buf = new unsigned char[len];
        if(read(fd, buf, len) != len) {
          printf("File is corrupted - record seems corrupt\n");
          exit(EXIT_FAILURE);
        }
        hash->Update(buf, len);
        delete buf;
      }
      buf = new unsigned char[16];
      if(read(fd, buf, 16) != 16) {
        printf("File is corrupted - unable to read in hash value\n");
        exit(EXIT_FAILURE);
      }
      hash->SetExpected(buf, 16);
      delete buf;

      if(hash->Matches() == false) {
        printf("File is corrupted - checksum does not match\n");
        exit(EXIT_FAILURE);
      }

      // Almost finished - let's point fd back to the start.
      if(lseek(fd, 0, SEEK_SET) == -1) {
        printf("Unable to wind back file, exiting.\n");
        exit(EXIT_FAILURE);
      }
    }

    BaseClass* HandleMOOV(unsigned int len)
    {
      BaseClass *ret, *p;
      ret = NULL;
      unsigned int tlen;
      unsigned char tag[4];
      unsigned char *buf;
      bool known;

      ret = p = NULL;
      buf = NULL;

      while(len) {
        if(read(fd, &tlen, sizeof(unsigned int)) != sizeof(unsigned int)) {
          printf("Tag len invalid");
          exit(EXIT_FAILURE);
        }
        tlen = ntohl(tlen);
        tlen -= 4;
        if(read(fd, tag, 4) != 4) {
          printf("Unable to read tag\n");
          exit(EXIT_FAILURE);
        }

        known = false;

        if(memcmp(tag, "FRNM", 4) == 0) {
          if(ret == NULL) {
            ret = new FRNM;
            p = ret;
          } else {
            p->next = new FRNM;
            p = p->next;
          }
          printf("p is at 0x%08x\n", p);
          if(buf != NULL) delete buf;
          buf = new unsigned char[tlen+1];
          printf("buf is at 0x%08x\n", buf);
          if(read(fd, buf, tlen) != tlen) {
            printf("Unable to read frame name buffer\n");
            exit(EXIT_FAILURE);
          }
          p->SetBuffer(buf, tlen);
          //delete buf;
          known = true;
        }

        if(memcmp(tag, "FRDT", 4) == 0) {
          if(ret == NULL) {
            ret = new FRDT;
            p = ret;
          } else {
            p->next = new FRNM;
            p = p->next;
          }
          if(buf != NULL) delete buf;
          buf = new unsigned char[tlen];
          if(read(fd, buf, tlen) != tlen) {
            printf("Unable to read frame data buffer\n");
            exit(EXIT_FAILURE);
          }
          //delete buf;
          p->SetBuffer(buf, tlen);
          known = true;
        }

        if(known == false) {
          if(lseek(fd, tlen, SEEK_CUR) == -1) {
            printf("Unable to adjust file index\n");
            exit(EXIT_FAILURE);
          }
        }
        len -= tlen;
      }
      if(buf) delete buf;
      return ret;
    }

    BaseClass *Process()
    {
      unsigned int len;
      unsigned char tag[4];
      this->CheckHash();
      MOOV *ret;

      if(read(fd, &len, sizeof(unsigned int)) != sizeof(unsigned int)) {
        printf("Unable to read from file.\n");
        exit(EXIT_FAILURE);
      }

      if(read(fd, tag, 4) != 4) {
        printf("Unable to read initial tag\n");
        exit(EXIT_FAILURE);
      }

      if(memcmp(tag, "MOOV", 4) != 0) {
        printf("Initial tag is not a MOOVie\n");
        exit(EXIT_FAILURE);
      }
      ret = new MOOV;
      ret->child = this->HandleMOOV(ntohl(len)-4);

      return ret;
    }
};

void wipearray(char **array)
{
  /*
   * This should be pretty trivial without relying on stack
   * values :)
   */

  while(*array) {
    memset(*array, 0, strlen(*array));
    array++;
  }
}

void wipeenv(char **argv, char **envp)
{
  wipearray(argv);
  wipearray(envp);
}

void DebugTree(BaseClass *obj, int spaces)
{
  int i;
  //printf("DebugTree: %08x\n", obj);

  for(; obj != NULL; obj = obj->next) {
    //printf("printing spaces\n");

    for(i = 0; i < spaces; i++) printf(" ");
    obj->PrintBuffer();
    if(obj->child) {
      //printf("Recursing..\n");
      DebugTree(obj->child, spaces + 2);
    }

  };
}

int main(int argc, char **argv, char **envp)
{
  int fd;
  BaseClass *ret;

  bool debug = getenv("DEBUG") ? true : false;

  Processor *processor;

  if(argc < 2) {
    printf("No filename specified\n");
    exit(EXIT_FAILURE);
  }

  processor = new Processor;
  processor->Open(argv[1]);

  wipeenv(argv, envp);

  ret = processor->Process();
  if(debug) {
    DebugTree(ret, 0);
  }
}
