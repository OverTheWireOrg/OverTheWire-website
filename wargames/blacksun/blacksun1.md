---
layout: default
gamename: blacksun
level: 1
---
Level1 is a trivial stack buffer overflow. Note that you'll probably
find it easier to use the compiled version than compiling it from
source.

### Binary information

| Stack smashing protection (SSP): 	      | Disabled	|
| Postition Independent Executable (PIE):     | Disabled	|
| Address space layout randomisation (ASLR):  | Enabled - No PIE|
| Non-executable pages: 		      | None / disabled	|
|--------------------------------------------:+:----------------|
| Location: 				      | /levels/level1  |

{% include showFile.html path="blacksun1.c" %}
