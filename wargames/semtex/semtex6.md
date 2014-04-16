---
layout: default
gamename: semtex
level: 6
---
ICMP forging
------------
Send a special ICMP packet to an unknown host. Add the correct
payload to it, to make sure you can receive the password. Spoof your
origin address and make semtex believe, the packet is really coming
from some government server (\*.gov) Make sure this server you are
sending from has a reverse DNS entry, otherwise you will not receive
an answer.

You find more specific information in your home directory.
** Note: You will have to use /semtex/semtexraw. Take a look at the source**

Reading Material
----------------
- [ICMP Request For Comment][]
- [Mixter's raw socket tutorial][]

{% include showFile.html path="semtex6.rawwrapper.c" %}

[ICMP Request For Comment]: http://www.faqs.org/rfcs/rfc792.html
[Mixter's raw socket tutorial]: http://mixter.void.ru/rawip.html
