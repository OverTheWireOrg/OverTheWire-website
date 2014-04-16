---
layout: default
gamename: vortex
level: 11
---
Chunk Corruption
----------------
You must corrupt the heap in order to gain arbitrary control of this
program. Do recall, the application is using phkmalloc.

Reading Material
----------------
- [BSD Heap Smashing][]
- [Once upon a free()][]
- [Advanced Doug Lea's malloc exploits][]
- [Exploiting the Wilderness][]

{% include showFile.html path="vortex11.c" %}
{% include showFile.html path="phkmalloc.c" %}

[BSD Heap Smashing]: http://freeworld.thc.org/root/docs/exploit_writing/BSD-heap-smashing.txt
[Once upon a free()]: http://www.phrack.org/issues.html?issue=57&id=9#article
[Advanced Doug Lea's malloc exploits]: http://www.phrack.org/issues.html?issue=61&id=6#article
[Exploiting the Wilderness]: http://archive.cert.uni-stuttgart.de/vuln-dev/2004/02/msg00025.html
