---
layout: default
gamename: vortex
level: 3
---
A Stack Overflow with a Difference
----------------------------------
This level is pretty straight forward. Just sit down and understand
what the code is doing. Your shellcode will require a
setuid(LEVEL4\_UID) since bash drops effective privileges. You could
alternatively write a quick setuid(geteuid()) wrapper around bash.

 **NOTE:** ctors/dtors might no longer be writable, although this
level is compiled with *-Wl,-z,norelro*. Lookup some information
about this e.g. [here][]

Reading Material
----------------
- [Smashing the Stack for Fun and Profit][]
- [Bypassing StackGuard and StackShield][]

{% include showFile.html path="vortex3.c" %}

[here]: http://unix.stackexchange.com/questions/8062/dtors-looks-writable-but-attempts-to-write-segfault
[Smashing the Stack for Fun and Profit]: http://phrack.org/issues/49/14.html#article
[Bypassing StackGuard and StackShield]: http://www.phrack.org/issues.html?issue=56&id=5#article
