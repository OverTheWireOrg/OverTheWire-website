---
layout: default
gamename: blacksun
level: 2
---
Level2 is a test application from a [pop3 library][] that's pretty
buggy. The idea is to write a pop3 server to trigger a vulnerability
(pick any you like :p) in the code and get a shell.

**Notes**

-   -fpic -fPIC was added to the compile options to remote DT\_TEXTREL's
    :p
-   If you're feeling generous, perhaps drop the author a note about any
    bugs you find so that future versions of the library can be fixed.
-   ASLR remote fun!

Binary information

### Binary information

| Stack smashing protection (SSP):            | Disabled        							|
| Postition Independent Executable (PIE):     | Disabled        							|
| Address space layout randomisation (ASLR):  | Enabled 								|
| Non-executable pages:                       | None / disabled 							|
|--------------------------------------------:+:------------------------------------------------------------------------|
| Code Location:                              | /levels/2/libspopc-0.7, using poptest1.c, and associated library code 	|
|---------------------------------------------+-------------------------------------------------------------------------|
| Location:                                   | /levels/level2							 	|

  [pop3 library]: http://brouits.free.fr/libspopc/
