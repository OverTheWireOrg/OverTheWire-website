cobjects = $(patsubst %.c,%.c.colored.html,$(wildcard *.c))
hobjects = $(patsubst %.h,%.h.colored.html,$(wildcard *.h))
binobjects = $(patsubst %.bin,%.bin.sums,$(wildcard *.bin))

all: $(cobjects) $(hobjects) $(binobjects)

%.c.colored.html: %.c
	code2html -N -H $< $@

%.h.colored.html: %.h
	code2html -N -H $< $@

%.bin.sums: %.bin
	echo -n " MD5SUM: " > $@
	md5sum $< | cut -d ' ' -f 1 >> $@
	echo -n "SHA1SUM: " >> $@
	sha1sum $< | cut -d ' ' -f 1 >> $@
