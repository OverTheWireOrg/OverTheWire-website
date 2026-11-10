---
layout: default
listinformation: true
title: Discord-IRC bridge - Privacy Policy
---

Discord-IRC bridge: Privacy Policy
==================================

*Last updated: 2026-11-10*

This Privacy Policy explains how the OverTheWire community ("OverTheWire", "we") handles
personal data when it runs the bot that connects (bridges) the channels on our
[Discord server][chat] to the channels on our [IRC server][chat]. The bot is based on the
open-source [discord-irc][] software. Please also read the [Terms of Service][tos] for the
bridge.

1. Who is responsible
---------------------
The bridge is run by the volunteers of the OverTheWire community. You can contact us about
privacy questions through the channels on the [Contact via Chat][chat] page. Please ask for a
staff member.

2. Which data the bridge handles
--------------------------------
The bridge only handles messages that are posted in the channels it is set up to bridge. It
does not read direct messages or other channels. For those bridged channels, it processes:

**From Discord**

- the content of your messages, including mentions and links to attachments;
- your Discord username, display name or server nickname, and your Discord user ID. The user
  ID is used to resolve mentions and display names;
- the name of the channel where the message was posted.

**From IRC**

- the content of your messages;
- your IRC nickname;
- the name of the channel where the message was posted.

To do this, the bot needs Discord's "Message Content" and "Server Members" permissions
(privileged gateway intents). It uses them only for the purposes described in this policy.

3. Why we process this data
---------------------------
We use this data only to run the bridge. This means copying each message, with the name of the
person who wrote it, from one platform to the other, so that Discord and IRC users can talk to
each other in the same channels. We do not use it for advertising, profiling, analytics or any
other purpose. We do not sell it or share it with anyone, except as described in section 5.

We process this data because we have a legitimate interest in providing a shared community chat
for OverTheWire players, and you choose to post in a public, bridged channel.

4. Storage and retention
------------------------
The bridge relays messages in real time. **OverTheWire does not store or archive the content of
relayed messages.** While the bot is running, it keeps the data it needs to work, such as the
list of channel members and their nicknames, in memory. This data is discarded when the bot
restarts.

The bot may write short operational logs, such as connection status and error messages. These
logs are used only to keep the bridge working, and they are not used to record conversations.

5. Who can see your messages
----------------------------
Bridged channels are public. When your message is relayed, it becomes visible to:

- **users on the other platform.** Discord messages become visible to everyone connected to the
  IRC channel, and IRC messages become visible to everyone in the Discord channel;
- **Discord.** Messages from IRC are posted to Discord, together with the IRC nickname, and are
  stored by Discord under the [Discord Privacy Policy][discord-privacy];
- **the IRC network.** Messages relayed to IRC are sent through the OverTheWire IRC server. IRC
  users can connect without encryption (port 6667), so messages may be sent unencrypted
  between the server and those users.

Other users, their IRC clients and their bots may log or save messages on their own. OverTheWire
does not control this. Do not post anything in a bridged channel that you would not want to be
public.

Links to Discord attachments that are relayed to IRC point to Discord's servers. If someone opens
them, Discord's policies apply.

6. Your rights
--------------
Depending on where you live, data protection law (such as the EU General Data Protection
Regulation) may give you the right to access, correct, delete or object to the processing of
your personal data. Because we do not store message content, there is usually no stored data
about you that we could hand over or delete.

Keep the following in mind:

- If you delete or edit a message on Discord, the copy on IRC does not change. A message that
  has already been relayed cannot be recalled.
- Copies on Discord are under Discord's control. You can manage your Discord data through your
  Discord account settings.
- If you do not want your messages to be relayed, do not post in the bridged channels.

If you have a question or request, contact the staff as described in section 1. If you live in
the EU, you also have the right to file a complaint with your local data protection authority.

7. Children
-----------
The bridge is not meant for children under the minimum age that Discord requires in their
country (at least 13). We do not knowingly process data from children under that age.

8. Changes to this policy
-------------------------
We may update this policy from time to time. Changes are published on this page, and the
"Last updated" date above is changed.

[chat]: /information/chat.html
[tos]: /information/discord-bot-tos.html
[discord-irc]: https://github.com/reactiflux/discord-irc
[discord-privacy]: https://discord.com/privacy
