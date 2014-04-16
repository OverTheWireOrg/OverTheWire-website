---
layout: default
gamename: blacksun
level: 0
---
Level0 is a remote format string intended to get you started with
blacksun. It is a remote format string bug with you being able to see
the reply, with address space randomisation enabled. You'll need to use
the direct parameter access method to analyse the stack and to
manipulate it.

Once getting access to a shell, read /etc/motd for more information

### Binary information

| Stack smashing protection (SSP):            | Enabled         				|
| Postition Independent Executable (PIE):     | Enabled         				|
| Address space layout randomisation (ASLR):  | Enabled         				|
| Non-executable pages:                       | None / disabled                             	|
|--------------------------------------------:+:------------------------------------------------|
| Location:                                   | Connect to blacksun.overthewire.org on port 79 	|

Alternatively, there is a debug version on port 78 if you need help
understanding what you're seeing

{% include showFile.html path="blacksun0.c" %}
