CC = gcc

APPS  = alignmemt network_order
APPS += ptr_array unit_1p256

all: $(APPS)

alignmemt: alignmemt.c
	$(CC) -Wall -o $@ $<

network_order: network_order.c
	$(CC) -Wall -o $@ $<

ptr_array: ptr_array.c
	$(CC) -Wall -o $@ $<

unit_1p256: unit_1p256.c
	$(CC) -Wall -o $@ $<

clean:
	@rm -f $(APPS)
