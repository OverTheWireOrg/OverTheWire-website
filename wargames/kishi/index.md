---
layout: default
listgames: true
title: [RELEASED] Kishi (HES2013 and NSC2013)
---

[RELEASED] Kishi (HES2013 and NSC2013)
======================================

This wargame was introduced at the [Hackito Ergo Sum (HES)][HES] 2013 and [No Such Con (NSC)][NSC] 2013 conferences in Paris and is centered around
the **fictictious North-Korean cyberops training facility Kishi**

As of December 2014, the Kishi game has been released to the public and can be
downloaded through [Vagrant] for VirtualBox by typing:

	vagrant init StevenVanAcker/kishi
	vagrant up

Kishi listens on ports 22, 80 and 2222, which are forwarded from the VM host
through ports 6622, 6680 and 3322 respectively.
Kishi uses several LXC containers internally, you can access them from the host
VM through

	virsh -c lxc://

The SSH server running on port 2222 can be used to login to kishi itself with
username/password vagrant/vagrant.  All containers run an SSH server with an
admin account with username/password otw/otw.  These admin accounts are not
part of the game and should only be used for setting up or debugging. Change
their passwords if you connect the VM to a public network.

To start the game, visit Kishi's web server on port 80 (or port 6680 of the
host).

[HES]: http://hackitoergosum.org/
[NSC]: http://nosuchcon.org
[Kishi]: http://kishi.labs.overthewire.org
[Vagrant]: https://www.vagrantup.com/
[vagrantcloud]: https://atlas.hashicorp.com/StevenVanAcker/boxes/kishi
