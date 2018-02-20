---
layout: default
title: News
---

News
====

2018-01-31  Migrated to VMs + SSH keys changed
-------------------------------------------------

Some of the games have been moved to a VM based setup again. SSH keys are not persisted over redeployments. Don't be scared if you get a host key warning. What is at risk any way? You are connecting to a public box full of hackers, right? Good luck!


2017-06-06  Migrated to Docker + SSH keys changed
-------------------------------------------------

All shell-based games have been migrated to Docker. A consequence of that is that the SSH keys have been changed
and your SSH client will complain about it if you've connected to the games before.


2017-05-15  SSH setup changed
-----------------------------

Each game now has its own SSH port, in anticipation of a move to a new server
which has a similar setup.

2015-03-15  IRC network upgrades
--------------------------------

On March 18th, all servers in the IRC network will be upgraded to
only accept TLS with perfect forward secrecy ciphersuites. If your client
does not support this, upgrade your client or use an unencrypted connection.

2014-12-29  Drifter back online
-------------------------------

The drifter wargame had also been offline for a while, but has now been
revived.  You can find it at [drifter][]. Please enjoy this late
holiday-present and report any (unintended) bugs.

2014-12-24  Kishi released
--------------------------

The kishi wargame had been offline for a while, but has now been released
as a Vagrant VM. More information on [kishi][]. Merry christmas and best wishes
for 2015! May the year 2015 bring you many 0days!

2014-04-16  Website moved
-------------------------

This website moved to github pages, allowing easier edits by the community
in the form of pull requests towards the [OverTheWire website repository][github]

2013-10-29  Kishi is down
--------------------------

The [kishi][] game has been taken offline.

2013-10-01  Four more natas levels
-----------------------------------

Thanks to morla, I'm releasing 4 new levels to [natas][]: natas23
through natas27. Have fun!.

2013-07-11  WeChall Scoring
----------------------------

OverTheWire has been using the [WeChall][] scoreboard for a while
and it has proven to be a good addition. There is now more
information about this scoreboard and how to use it in [WeChall
Scoring][].

2013-06-28  6 new levels for natas
-----------------------------------

To celebrate my birthday, I'm releasing 6 new levels to [natas][]:
natas17 through natas23. Have fun!

2013-05-20  New game: Kishi
----------------------------

We just launched a new game called [kishi][1]. Enjoy!

2012-11-04  IRC and monxla down
--------------------------------

Due to a DDoS, we have temporarily taken down our IRC server and the
monxla wargame. If you need to contact us over IRC, you can find us
at smashthestack IRC.

2012-10-26  New game: Natas
----------------------------

We just launched a new game called [natas][2], which covers the
basics of serverside websecurity. Enjoy!

2012-10-08  New OTW beta
-------------------------

Hey folks, as you can see, the new OverTheWire *beta* just
launched - same awesome content, now also a lil' bit more awesome to
the eye.

If you find any bugs in the new layout, please don't hesitate to
contact us via mail or on IRC!

Cheers mates <3

2012-08-01
----------
 Two more intruded.net wargames: [utumno][] and [maze][] have been
added. Big thanks to adc, morla and reth!

2012-06-28
----------
 We have adopted 3 intruded.net wargames: [leviathan][], [narnia][]
and [behemoth][]. Big thanks to adc, morla and reth!

2012-05-30
----------
 The [bandit][] wargame has been expanded with 7 new levels

2012-05-11
----------
 We've been busy the last months preparing new games and resurrecting
old ones. We can now proudly announce that [krypton][] is back from
the ice, that all [vortex][] levels have been verified to work and
that there are 2 new wargames: [monxla][] and [bandit][]

2012-01-07
----------
<iframe width="420" height="315" src="http://www.youtube.com/embed/8h4T5UHuwXM" frameborder="0" allowfullscreen></iframe>

 Best wishes for 2012! We are releasing HES2010: more information
[here][]

2011-09-18
----------
<iframe width="420" height="315" src="http://www.youtube.com/embed/A4MFZjwvzSE" frameborder="0" allowfullscreen></iframe>

 More information [here][3]

2011-08-27
----------
 We are currently migrating some services to different hosting
providers and in the process will be retiring some wargames and
releasing their diskimages into the wild. There are several
advantages to releasing old wargames:

-   it will allow you as a player to play offline, whenever you want
-   you will be able to rip apart levels as they are set up, and have a closer look at them
-   you can host the wargame at your own lanparty!
-   it will give you insight in how a wargame is built, hopefully inspiring you to create your own (and of course [contribute it][] :))
-   Finally, it frees up resources on the OverTheWire servers so that we can host new wargames

More information about this soon!

[drifter]: /wargames/drifter/
[kishi]: /wargames/kishi/
[natas]: /wargames/natas/
[WeChall]: https://www.wechall.net
[WeChall Scoring]: /about/wechall.html
[1]: /wargames/kishi
[2]: /wargames/natas
[utumno]: /wargames/utumno
[maze]: /wargames/maze
[leviathan]: /wargames/leviathan
[narnia]: /wargames/narnia
[behemoth]: /wargames/behemoth
[bandit]: /wargames/bandit
[krypton]: /wargames/krypton
[vortex]: /wargames/vortex
[monxla]: /wargames/monxla
[here]: /wargames/hes2010
[3]: /wargames/abraxas
[contribute it]: /about/contribute.html
[github]: https://github.com/StevenVanAcker/OverTheWire-website
