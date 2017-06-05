---
layout: default
listhelp: true
title: SSH/infrastructure
---

SSH and the infrastructure
==========================

All ssh-based games on OverTheWire run in [Docker] containers.
When you login with SSH to one of the games, a fresh Docker container is created just for you.
Noone else is logged in into your container, nor are there any files from other players lying around.
We opted for this setup to provide each player with a clean environment to experiment and learn in,
which is automatically cleaned up when you log out.

Because of this setup, things are not as straightforward as one would think.
Take SSH for example. Each SSH connection creates a new environment to work in.
Most of the time, this works nicely. However, there are cases where this is a problem.

Consider for instance a level where you must log in twice to the same container.
Because of the way things are set up, logging in twice will give you access to different containers,
each with a clean working environment and not able to affect each other. This is not what you want.

Luckily, there are ways around this.
One way is to use SSH with port forwarding.
For instance:

	ssh -l bandit0 -p 2220 -L 1234:localhost:22 bandit.labs.overthewire.org

With this command, you connect to the [bandit] game on port 2220 with username bandit0,
and instruct your SSH client to set up port forwarding from port 1234 on your local computer,
to port 22 on "localhost" as seen from the bandit container.
What this means is that port 1234 on your local computer is forwarded to the SSH server inside the one bandit container
that was created for you.
If you connect several times to "localhost" port 1234 on your own computer, you end up each time in
the same container.

As long as you keep the initial SSH connection, which forwards the port, open, you will be able to login to the same container.
Remember that the container will be inaccessible as soon as you close this connection!

Also see the help page about persisting [User data].

[Docker]: https://www.docker.com/
[bandit]: /wargames/bandit
[User data]: userdata.html
