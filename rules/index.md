---
layout: default
title: Rules
---

Rules
=====

The goal of the OverTheWire games is to provide educational resources to people willing to learn<br>
topics on cybersecurity. The OverTheWire community hosts these resources free of charge for players<br>
to use and learn from. However, usage of these resources comes with a few simple rules.

In general
----------
1. **Treat everyone with respect**. We will not tolerate any form of harassment or discrimination.
2. **We do not allow unsolicited spam or self-promotion** in the chatrooms or private messages.
3. **Do not spoil the game** for others in the chatrooms. If you need help, specify the game and<br>
   level and someone will help you in private messages. Do not rely on Discord's `/spoiler` <br>
   functionality as the chatrooms are connected to IRC where this functionality is not available.
4. Do not use easy to guess file- or directory names and **clean up after yourself**. If you have<br>
   created files or directories, please remove them when you are done.

For educators and content-creators
----------------------------------
1. **Do not publish credentials** to any of the games. We understand the need to create writeups,<br>
   walkthroughs, and tutorials, but do not publish any credentials.
2. If you are profiting from the content you create and you are able to afford it,<br>
   **please [consider donating][]** a portion of your earnings to the OverTheWire community.<br>
   We are a community of volunteers which relies on donations to keep the lights on.
3. Please **give credit where credit is due**. If you are using content from the OverTheWire games,<br>
   please mention the OverTheWire community and provide a link to our website.

<div id="accept-rules">
	<button id="accept-rules-button" class="btn btn-primary">Click here to accept these rules</button>
</div>

<div id="rules-accepted" style="display: none;">
<span class="checkmark">&check;</span><br>
Thank you for accepting the rules. Have fun playing the games!
</div>

<script>
function hideAcceptButton() {
	$("#rules-accepted").show();
	$("#accept-rules").hide();
	localStorage.setItem("rules-accepted", "true");
}

$("#accept-rules-button").click(hideAcceptButton);
$("#please-read-the-rules").hide();

if (localStorage.getItem("rules-accepted") === "true") {
	hideAcceptButton();
} else {
	showAcceptButton();
}

</script>



[consider donating]: /information/donate.html
