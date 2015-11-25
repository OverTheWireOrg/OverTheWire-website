---
layout: default
gamename: bandit
level: 17
---
Level Goal
----------
The credentials for the next level can be retrieved by submitting the
password of the current level to **a port on localhost in the range
31000 to 32000**. First find out which of these ports have a server
listening on them. Then find out which of those speak SSL and which
don't. There is only 1 server that will give the next credentials, the
others will simply send back to you whatever you send to it.

Commands you may need to solve this level
-----------------------------------------
ssh, telnet, nc, openssl, s\_client, nmap

Helpful Reading Material
------------------------
- [Port scanner on Wikipedia][]

[Port scanner on Wikipedia]: http://en.wikipedia.org/wiki/Port_scanner
