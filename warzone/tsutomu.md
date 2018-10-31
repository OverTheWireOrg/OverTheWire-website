---
layout: default
listwarzone: true
title: Tsutomu
---

Tsutomu
=======

Tsutomu is a machine in the warzone that replicates the network and computer setup
of [Tsutomu Shimomura], who got hacked by [Kevin Mitnick] on December 25th 1994.

Kevin Mitnick used a [TCP sequence prediction attack], known to exist since [at
least the mid-1980s], to fake a legitimate connection to Tsutomu
Shimomura's RSH server.

![TCP handshake](https://upload.wikimedia.org/wikipedia/commons/9/98/Tcp-handshake.svg)

In TCP sequence prediction attacks, an attacker impersonates a Client and
completes a [TCP handshake] between that Client and a Server, without ever
receiving any packets that the Server sends back to the Client. In order to do
so, the attacker must correctly guess the initial sequence number (ISN) sent
from the Server to the Client. The kernel on Tsutomu Shimomura's machine
generated easily predictable ISNs, making the attack possible.

The attack is featured in the movie [Takedown], but it's not a very good source
of information on the technical aspects of the attack itself.

Easily predictable TCP initial sequence numbers became extinct in 1996 with the
introduction of [RFC 1984].
The tsutomu machine inside the warzone reintroduces easily predictable ISNs so that you
can try out this attack for yourself and test your skills.


How to play
-----------

After connecting to the warzone, tsutomu can be found at <http://172.16.123.4>.

To avoid interfering with others working on tsutomu, you may find it helpful to
coordinate in the #warzone channel on our IRC server.

[Tsutomu Shimomura]: https://en.wikipedia.org/wiki/Tsutomu_Shimomura
[Kevin Mitnick]: https://en.wikipedia.org/wiki/Kevin_Mitnick
[TCP sequence prediction attack]: https://en.wikipedia.org/wiki/TCP_sequence_prediction_attack
[at least the mid-1980s]: https://pdos.csail.mit.edu/~rtm/papers/117.pdf
[TCP handshake]: https://en.wikipedia.org/wiki/Transmission_Control_Protocol#Connection_establishment
[RFC 1984]: https://tools.ietf.org/html/rfc1948
[Takedown]: https://www.imdb.com/title/tt0159784/
