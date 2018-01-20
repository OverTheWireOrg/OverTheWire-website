---
layout: default
gamename: bandit
level: 21
---
Level Goal
----------
There is a setuid binary in the homedirectory that does the
following: it makes a connection to localhost on the port you
specify as a commandline argument. It then reads a line of text from
the connection and compares it to the password in the previous level
(bandit20). If the password is correct, it will transmit the
password for the next level (bandit21).

 **NOTE:** [Changes to the infrastructure](http://overthewire.org/help/sshinfra.html) made this level more difficult. You will need to figure out a way to launch multiple commands in the same Docker instance.

 **NOTE 2:** Try connecting to your own network daemon to see if it
works as you think

Commands you may need to solve this level
-----------------------------------------
ssh, nc, cat, bash, screen, tmux, Unix Background Jobs (bg, fg, jobs, &, CTRL-Z, ...)

