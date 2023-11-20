---
layout: default
gamename: drifter
level: 0
---
Drifter can be accessed on drifter.labs.overthewire.org via SSH on port 2230. Level 0 listens
on port 1111.

Level0 is an extremely trivial, encrypted, remote syscall proxy. Your
aim is to read the contents of a file called "drifter0.password" to get the
password for user drifter0.

Upon connection, it sets up an encrypted rc4 key (based on the
connecting IP address / port), read()'s in 9 integers, and then decrypts
them, and handles them off to syscall(). This allows the network client
to execute arbitrary syscalls in a safe way.

To give you an idea of what's needed:

**You'll need to**

1.  If you are behind a NAT/PAT, you might want to do vortex level0, and
    complete this level from vortex, as otherwise your known IP address
    and port information changes.
2.  Examine how the RC4 keys are generated, and how they are applied
3.  [mmap2()][] some memory. You will get the address where the memory
    was allocated in the response from the server. mmap2() takes its
    arguments from registers, not the stack.
4.  [read()][] into that allocated buffer to get the file name. The
    source fd that you need will be 4. (0-2 = stdin/stdout/stderr, 3
    will be network socket, so 4 in next in line. You will want to read
    in enough data for the filename "instructions"
5.  Write the filename ("instructions" sans quotes) to the allocated
    memory location to your client socket
6.  [open()][] the "instructions" file. You will get the fd it was
    allocated to in response
7.  [read()][] from the allocated file descriptor to your allocated
    memory
8.  [write()][] from the allocated buffer to the socket on the server
    (fd 4)

Once all that is done, you will have the contents of the instructions
file printed to your screen.

Of course - this does not prevent you from using other mechanisms to
access the server, such as using "shelldemo" from metasploit 2.x to
examine the environment. In fact, using shelldemo is probably a good
exercise as well.

There are 32bits syscalls and 64 bits syscalls, conforming to the CPU architecture. 
For 32 bits processor , consult [x32_syscalls]
For 64 bits processor, consult [x64_syscalls]
If you want, you can use "man 2 read" or "man 2 write", for getting paramaters and return value of determinated syscall. 


The following sourcecode is located in /drifter/drifter0_src/ :

{% include showFile.html path="drifter0.c" %}
{% include showFile.html path="rc4.c" %}
{% include showFile.html path="rc4.h" %}

  [mmap2()]: https://man7.org/linux/man-pages/man2/mmap2.2.html
  [read()]: https://man7.org/linux/man-pages/man2/read.2.html
  [open()]: https://man7.org/linux/man-pages/man2/open.2.html
  [write()]: https://man7.org/linux/man-pages/man2/write.2.html
  [x64_syscalls]: https://github.com/torvalds/linux/blob/master/arch/x86/entry/syscalls/syscall_64.tbl
  [x32_syscalls]: https://github.com/torvalds/linux/blob/master/arch/x86/entry/syscalls/syscall_32.tbl
 
