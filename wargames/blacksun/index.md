---
layout: default
gamename: blacksun
---
{% include beginNote.html title="2012-04-17 - blacksun is temporarily down" %}
The blacksun wargame is temporarily down because we have lost the backup
(shame on us). We are currently collecting the levels from third parties
to bring the game back.
{% include endNote.html %}

### About

Blacksun is a PullThePlug / OverTheWire wargame that is meant to help
people learn more advanced exploitation techniques against hardened
hosts and environments. It is implemented by PaX patches, and the
Hardened Gentoo project. **It is a work in process** If you have any
questions you can contact [andrewg][] via email.

Blacksun is not an exploit novice's game / toolset, as it assumes a
bunch of previous knowledge, such as programming, format string
exploitation, heap exploitation, shellcoding, and out of the box
thinking, amongst other things. However, PullThePlug / OverTheWire does
have another wargame that's a lot easier, but still quite challenging
available [here][].

**Also, it is not meant to discredit any of the work that has been done
towards PaX (hi pipacs!), as it is quite awesome. Perhaps even it will
lead to better defensive, and maybe better offensive techniques. And
most likely greater understanding with the issues involved.**

### Aims

Blacksun is aimed towards demonstrating and helping people better
understand:

-   Address space randomisation
-   Non executable memory and things that affect it
-   Stack smashing prevention
-   Information leaks
-   Code auditing and identifying code paths and vulnerable constructs
-   Being able to construct the exploitation environment
-   Binary auditing, and differencing
-   Access control list systems

### Reading material

A list of suggested reading material can be found [here][readingmaterial]

  [andrewg]: mailto:andrewg@felinemenace.org
  [here]: /wargames/vortex/
  [readingmaterial]: reading_material.html
