---
layout: default
gamename: drifter
level: 1
---
Level 1 is a file parsing / heap corruption bug, with C++ classes.

There is no need to mess around with heap exploitation, and C++ lends
itself to relatively straight forward exploitation.

[SMASHING C++ VPTRS][] - Although keep in mind that compiler changes can
influence how things are laid out.

When looking over the below code, keep in mind what needs to be done to
enable debugging, and what SetBuffer does.

One last hint: In order to correctly overflow the objects / pointers,
the allocation size will have to be similar to the class size ;) Even
blindly messing around will lead to code execution sooner or later

  [SMASHING C++ VPTRS]: http://www.phrack.org/issues.html?issue=56&id=8
