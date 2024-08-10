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
listening on them. Then find out which of those speak SSL/TLS and which
don't. There is only 1 server that will give the next credentials, the
others will simply send back to you whatever you send to it.

 **Helpful note: Getting "DONE", "RENEGOTIATING" or "KEYUPDATE"? Read the
"CONNECTED COMMANDS" section in the manpage.**

Commands you may need to solve this level
-----------------------------------------
[ssh](https://manpages.ubuntu.com/manpages/noble/en/man1/ssh.1.html)
,
[telnet](https://www.commandlinux.com/man-page/man1/telnet.1.html)
,
[nc](https://linux.die.net/man/1/nc)
,
[ncat](https://manpages.ubuntu.com/manpages/noble/en/man1/ncat.1.html)
,
[socat](https://manpages.ubuntu.com/manpages/noble/en/man1/socat.1.html)
,
[openssl](https://manpages.ubuntu.com/manpages/noble/en/man1/openssl.1ssl.html)
,
[s\_client](https://manpages.ubuntu.com/manpages/noble/en/man1/s_client.1ssl.html)
,
[nmap](https://manpages.ubuntu.com/manpages/noble/en/man1/nmap.1.html)
,
[netstat](https://manpages.ubuntu.com/manpages/noble/en/man8/netstat.8.html)
,
[ss](https://manpages.ubuntu.com/manpages/noble/en/man8/ss.8.html)

Helpful Reading Material
------------------------
- [Port scanner on Wikipedia][]

[Port scanner on Wikipedia]: https://en.wikipedia.org/wiki/Port_scanner
