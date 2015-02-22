---
layout: default
gamename: blacksun
title: Reading material
---

Reading material
================

Below is a list of overall reading material which you may wish to read
over before starting.

Bug class exploitation
----------------------

### Format strings:

-   [Scut's formatstring paper][] (class paper and recommended reading)
-   [Advances in format string exploitation][]
-   [Format bug analysis][]
-   [Vulnerabilities in your code - Format Strings][]
-   [The Mystery of Format String Exploitation][]

### Heap exploitation

-   [Once upon a free()][] - Historical document, later glibc's have
    additional checking
-   [Vudo - An object superstitiously believed to embody magical
    powers][] - ""
-   [Advanced Doug lea's malloc exploits][] - ""
-   [Malloc Maleficarum][] - Recent glibc malloc exploitation document,
    should be relevant for blacksun

### Frame pointer overwrites

-   [Framepointer overwrites][]

### Adress space layout randomisation (ASLR)/ PaX specific

-   [Bypassing PaX ASLR protection][] - somewhat outdated.
-   [The advanced return-into-lib(c) exploits: PaX case study][] - ""
-   [PaX documentation][] - external link
-   [Smash the stack - Advanced bufferoverflow methods][]

### Execshield documents

-   [A Solution To Red Hat PIE Protection][] - External link
-   [How to Exploit Overflow Vulnerability Under Fedora Core][] -
    External link

### Stackguard / Stack smashing protection

-   [Stack Smashing Protection homepage][] - external link
-   [Bypassing StackGuard and StackShield][]
-   [Four different tricks to bypass StackShield and StackGuard protection][]
-   [Defeating compiler-level buffer overflow protection][]

### Hardware protection (e.g amd64 / nx bit)

-   [x86-64 buffer overflow exploits and the borrowed chunks exploitation technique][]

Generalised papers / notes / presentations (not always indepth)
---------------------------------------------------------------

-   [A Comparison of Buffer Overflow Prevention Implementations and Their Weaknesses][]
-   [Spender's PaX Presentation][]
-   [Taking the fun out of smashing the stack][]
-   [Practical Unix Security][]
-   [PaX Memory Protection][] - Linux Journal entry
-   [Advances In Software Attack][]

Secure computing
----------------

-   [Seccomp announcement][] - Secure Computing (seccomp) patch announcement (external link)

Got some good additional papers?
--------------------------------

If you have some relevant papers that would be suitable for this site,
please drop [me][] an email.

  [Scut's formatstring paper]: papers/formatstring-1.2.tar.gz
  [Advances in format string exploitation]: papers/p59-0x07.txt
  [Format bug analysis]: papers/format-bug-analysis.pdf
  [Vulnerabilities in your code - Format Strings]: papers/core_format_strings.pdf
  [The Mystery of Format String Exploitation]: papers/rebel-formatstring.txt
  [Once upon a free()]: papers/p57-0x09
  [Vudo - An object superstitiously believed to embody magical powers]: papers/p57-0x08
  [Advanced Doug lea's malloc exploits]: papers/p61-0x06_Advanced_malloc_exploits.txt
  [Malloc Maleficarum]: papers/MallocMaleficarum.txt
  [Framepointer overwrites]: papers/P55-08
  [Bypassing PaX ASLR protection]: papers/p59-0x09.txt
  [The advanced return-into-lib(c) exploits: PaX case study]: papers/p58-0x04
  [PaX documentation]: http://pax.grsecurity.net/docs/
  [Smash the stack - Advanced bufferoverflow methods]: papers/smash_the_stack_advanced_bufferoverflow_methods.txt
  [A Solution To Red Hat PIE Protection]: http://www.hackinthebox.org/print.php?sid=15604
  [How to Exploit Overflow Vulnerability Under Fedora Core]: http://neworder.box.sk/newsread.php?newsid=13007
  [Stack Smashing Protection homepage]: http://www.research.ibm.com/trl/projects/security/ssp/
  [Bypassing StackGuard and StackShield]: papers/p56-0x05
  [Four different tricks to bypass StackShield and StackGuard protection]: papers/StackguardPaper.pdf
  [Defeating compiler-level buffer overflow protection]: papers/alexander0506.pdf
  [x86-64 buffer overflow exploits and the borrowed chunks exploitation technique]: papers/no-nx.pdf
  [A Comparison of Buffer Overflow Prevention Implementations and Their Weaknesses]: papers/Buffer_Overflow_Prevention.ppt
  [Spender's PaX Presentation]: papers/PaX-presentation.ppt
  [Taking the fun out of smashing the stack]: papers/smashing.sxi
  [Practical Unix Security]: papers/practical_unix_security.pdf
  [PaX Memory Protection]: papers/PaX_Memory_Protection.pdf
  [Advances In Software Attack]: papers/advancesinsoftwareattacks.pdf
  [Seccomp announcement]: http://kerneltrap.org/node/4005
  [me]: mailto:andrewg@felinemenace.org
