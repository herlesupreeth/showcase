CC = gcc

APPS  = ambiguous alignmemt cpu_speed network_order
APPS += ptr_array tick_msec unit_1p256

all: $(APPS)

ambiguous: ambiguous.c
	$(CC) -Wall -o $@ $<

alignmemt: alignmemt.c
	$(CC) -Wall -o $@ $<

cpu_speed: cpu_speed.c
	$(CC) -Wall -o $@ $<

network_order: network_order.c
	$(CC) -Wall -o $@ $<

ptr_array: ptr_array.c
	$(CC) -Wall -o $@ $<

tick_msec: tick_msec.c
	$(CC) -Wall -o $@ $<

unit_1p256: unit_1p256.c
	$(CC) -Wall -o $@ $<

clean:
	@rm -f $(APPS)
