---
layout: default
gamename: vortex
level: 4
---
To exec or not to exec
----------------------
This is the common format string bug, exploit it with care though as
a check is made with argc. What is the layout of a process's memory?
How are programs executed?

Reading Material
----------------
- [Format String Technique][]
- [Exploiting Format String Vulnerabilities][]
- [Bypassing StackGuard and StackShield][]

{% include showFile.html path="vortex4.c" %}

[Format String Technique]: http://julianor.tripod.com/bc/NN-formats.txt
[Exploiting Format String Vulnerabilities]: http://julianor.tripod.com/bc/formatstring-1.2.pdf
[Bypassing StackGuard and StackShield]: http://www.phrack.org/issues.html?issue=56&id=5#article
