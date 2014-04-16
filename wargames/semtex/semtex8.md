---
layout: default
gamename: semtex
level: 8
---
Non-sniffable data
------------------
This level is about some very simple covert channel, about
transferring information that cannot possibly be sniffed.
There is a socket file in /rdx/nature. It is a local Unix socket.
Receive data from it until EOF and save it to a file.

Watch the time between the received bytes. Certain delays mean
certain bytes that have been left out (have not been sent).

    0-1 s : no special data
    1-2 s : 'Q'
    2-3 s : 'L'
    3-4 s : 'A'
    4-5 s : 'V'

you have to take these "unsent" data into your output file too,
exactly at the places where they occur.

Thus you are receiving data while not receiving anything.

The output file is a .jpg image :)

