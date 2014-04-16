---
layout: default
gamename: semtex
level: 12
---
Authentication Daemon
---------------------
There is an authentication daemon waiting on brebera port 24012. You
connect to it, supply your password and get authenticated. The
semtex 12 password will give you user access, the admin password
will give you administrator access...

After authentication you connect to the remote file system reader
on port 24013. Depending on your access level you can list files and
show them. The semtex 13 password has been located in one of the
files on this remote file system. Brebera is fast, can you be
faster?

Thanks to bk for this level!

{% include showFile.html path="semtex12.authd.c" %}
{% include showFile.html path="semtex12.daemon.c" %}
{% include showFile.html path="semtex12.reader.c" %}
{% include showFile.html path="semtex12.sem.c" %}
{% include showFile.html path="semtex12.sem.h" %}
{% include showFile.html path="semtex12.server.h" %}
