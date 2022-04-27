CC = gcc

APPS  = ambiguous alignmemt bit_field cpu_speed fra2bin
APPS += negative network_order proc_maps ptr_array
APPS += quine stdin tick_msec

all: $(APPS)

ambiguous: ambiguous.c
	$(CC) -Wall -o $@ $<

alignmemt: alignmemt.c
	$(CC) -Wall -o $@ $<

bit_field: bit_field.c
	$(CC) -Wall -o $@ $<

cpu_speed: cpu_speed.c
	$(CC) -Wall -o $@ $<

fra2bin: fra2bin.c
	$(CC) -Wall -o $@ $<

negative: negative.c
	$(CC) -Wall -o $@ $<

network_order: network_order.c
	$(CC) -Wall -o $@ $<

proc_maps: proc_maps.c
	$(CC) -Wall -o $@ $<

ptr_array: ptr_array.c
	$(CC) -Wall -o $@ $<

quine: quine.c
	$(CC) -Wall -o $@ $<

stdin: stdin.c
	$(CC) -Wall -o $@ $<

tick_msec: tick_msec.c
	$(CC) -Wall -o $@ $<

clean:
	@rm -f $(APPS)
