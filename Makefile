CC = gcc

APPS  = atoi ambiguous alignmemt arrayindex bit_field cpu_speed
APPS += float_inf float_nan fra2bin negative network_order
APPS += proc_maps ptr_array quine stdin tick_msec

all: $(APPS)

atoi: atoi.c
	$(CC) -Wall -o $@ $<

ambiguous: ambiguous.c
	$(CC) -Wall -o $@ $<

alignmemt: alignmemt.c
	$(CC) -Wall -o $@ $<

arrayindex: arrayindex.c
	$(CC) -Wall -o $@ $<

bit_field: bit_field.c
	$(CC) -Wall -o $@ $<

cpu_speed: cpu_speed.c
	$(CC) -Wall -o $@ $<

float_inf: float_inf.c
	$(CC) -Wall -lm -o $@ $<

float_nan: float_nan.c
	$(CC) -Wall -lm -o $@ $<

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
