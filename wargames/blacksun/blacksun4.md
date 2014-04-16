---
layout: default
gamename: blacksun
level: 4
---
level4 is an installation of Apache and PHP with an introduced heap
vulnerability.

The introduced vulnerability is as follows:

{% include showFile.html path="blacksun4.function.c" %}

Thanks to orix for the introduced code snippet

The document root is in /levels/level4/htdocs, you'll need to put your
php code there and call it via the webserver on port 55555.

**Note:** that if you're executing a shell, it can't be /bin/sh or
/bin/bash, oh, and the apache process can't access the /etc/pass
directory :P

### Binary information

| Stack smashing protection (SSP):            | Enabled         |
| Postition Independent Executable (PIE):     | Enabled         |
| Address space layout randomisation (ASLR):  | Enabled         |
| Non-executable pages:                       | None / disabled |
|--------------------------------------------:+:----------------|
| Location:                                   | 127.0.0.1:55555 |

{% include showFile.html path="blacksun4.basic_functions.c" %}

