CC=gcc
CFLAGS = -Wall -std=c99
LDLIBS = -lm

SOURCES = Zad01 Zad02 Zad03 Zad04

all: 	$(SOURCES)

Zad01: Zad01.c
	$(CC) -E $^
	
Zad02: Zad02.c
	$(CC) -E $^

clean:
	rm -f $(SOURCES)
	
.PHONY: all clean
