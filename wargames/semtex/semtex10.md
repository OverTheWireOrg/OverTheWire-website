---
layout: default
gamename: semtex
level: 10
---
Hacking szene
-------------
**Thanks to zaphod and Mush for finding a bugs in this level**

Do you know these hacking movies where they push some buttons, then
the evil hacker script window turns up and a percentage bar is
showing how far the password cracking has gone?


    0%....10%....20%....30%....40%....50%....60%....70%....80%....90%....100%
    password cracked!

Ever wanted to do it yourself? Here is your chance.\

This level implements a weakness in the authentication scheme used
by M$ win95 and win98 for the netbios shares.

There is a TCP daemon on brebera port 24019. It authenticates your
password. Once you send the correct password, it echoes it back.
Well, let the source speak for itself. As far as brute force may
take you, a little brain is never bad :P Perhaps you have heard of
pqwak?

{% include showFile.html path="semtex10.c" %}
