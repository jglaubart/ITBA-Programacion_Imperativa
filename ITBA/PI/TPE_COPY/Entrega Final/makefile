COMPILER=gcc
FLAGS=-pedantic -std=c99 -Wall -fsanitize=address
DEBUG_COMPILER=-g -DDEBUG=1
FILES=back.c front.c ticketsADT.c
OUTPUT_FILE=parkingTicketsCHI parkingTicketsNYC $(OBJECTS)
OBJECTS=$(FILES:.c=.o)

all: parkingTicketsCHI parkingTicketsNYC

parkingTicketsNYC:
	$(COMPILER) -o parkingTicketsNYC mainNYC.c $(FILES) $(FLAGS)

parkingTicketsCHI: 
	$(COMPILER) -o parkingTicketsCHI mainCHI.c $(FILES) $(FLAGS)

debug: COMPILER+=$(DEBUG_COMPILER)
debug: all

clean:
	rm -r $(OUTPUT_FILE)
