---
layout: default
listinformation: true
title: WeChall Scoreboard
---

WeChall Scoreboard
==================

OverTheWire makes use of a scoreboard provided by [WeChall][] to allow
players to track their own progress and promote some healthy competition
between players. To make use of this scoreboard for OverTheWire games,
you need to follow these steps:

Permenant Method:
1.  First, go to [WeChall][] and register for an account.
2.  Next, log in and retrieve your WeChall token and username. Your
    WeChall username is what you registered with, while your WeChall
    token can be found on the WeChall website under ["Account" ->
    "WarBoxes"][warboxlink]. The token looks something like
    "EDD76-1FC9F-7388B-DC6EB-E3F71-FC4CB".
3.  Next, assuming you are using a linux operating system, edit your
    ~/.bashrc file and add:

        export WECHALLUSER="YourUserName"
        export WECHALLTOKEN="YOUR-WECHALL-TOKEN-HERE"

    For `fish` users, you may run:

        set -Ux WECHALLUSER "YourUserName"

    You may need to logout and login again for these changes to take
    effect. To test whether the environment variables are registered,
    type "echo $WECHALLUSER", which should show that environment
    variable.

4.  Next, edit ~/.ssh/config (or create it if it doesn't exist) and
    add:

        Host *.labs.overthewire.org
          SendEnv WECHALLTOKEN
          SendEnv WECHALLUSER

    This configures your SSH client to transmit both username and token
    to your remote session, so it can be used there.

5.  Finally, you are able to easily register which levels you have
    beaten on OverTheWire by logging in through SSH the normal way, and
    invoking the "wechall" command. This command will use your WeChall
    username and WeChall token to register the level you have beaten
    with WeChall.
    
**Temporary One Time Inline Method:**  
In your preferred terminal, after editing the values for WECHALLUSER and WECHALLTOKEN, and probably the level after option -l, you can input the following command line for an inline one time ssh login:  
```ssh -o "SetEnv=WECHALLUSER=yourusername WECHALLTOKEN=00000-00000-00000-00000-00000-00000" -p 2220 bandit.labs.overthewire.org -l bandit0```

[WeChall]: https://www.wechall.net
[warboxlink]: https://www.wechall.net/warboxes
