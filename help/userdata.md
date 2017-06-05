---
layout: default
listhelp: true
title: User data
---

User data
=========

As described [before], all ssh-based games on OverTheWire run in [Docker] containers,
which means that the containers are destroyed when you log out from SSH.

You are free to store data anywhere you like, such as /tmp or even the home directories.
Keep in mind that all of these directories will be wiped when you log out, which can get annoying
if you just created that superfancy exploit and your SSH connection unexpectedly disconnects.

That is why we are offering persistent storage on the shell-games.
To make use of persistent storage, put the following in your SSH config:

<ol>
<li>
Assuming you are using the correct operating system and shell, edit your
~/.bashrc file and add:

{% include otwuserdir.html %}

You may need to logout and login again for these changes to take
effect. To test whether the environment variables are registered,
type "echo $OTWUSERDIR", which should show that environment
variable.
</li>
<li>
Next, edit ~/.ssh/config (or create it if it doesn't exist) and
add:
<pre>
        Host *.labs.overthewire.org
          SendEnv OTWUSERDIR
</pre>
This configures your SSH client to transmit the environment variable
to your remote session, so it can be used there.

</li>
</ol>

Upon the next login to one of the games, your persistent user directory will be created.
Don't lose the name of the directory, because you will not be able to recover it easily.
Also, be careful about sharing the name of your directory. Anyone with that knowledge can read and modify your files in there.


Also see the help page about [SSH and infrastructure].

[Docker]: https://www.docker.com/
[before]: sshinfra.html
[SSH and infrastructure]: sshinfra.html
