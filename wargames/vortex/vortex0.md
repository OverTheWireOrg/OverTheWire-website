---
layout: default
gamename: vortex
level: 0
---
Level Goal
----------
Your goal is to connect to port 5842 on vortex.labs.overthewire.org
and read in 4 unsigned integers in host byte order. Add these
integers together and send back the results to get a username and
password for vortex1. This information can be used to log in using
SSH.

**Note:** vortex is on an 32bit x86 machine (meaning, a little endian
architecture)

Helpful Reading Material
------------------------
- [C Programming Introduction][]
- [Network Programming Tutorial][]

  [C Programming Introduction]: http://beej.us/guide/bgc/
  [Network Programming Tutorial]: http://beej.us/guide/bgnet/
