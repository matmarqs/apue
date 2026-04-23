CC = gcc
CFLAGS = -std=c99 -g -Og -Wall -I./include
LDFLAGS =

PROGRAMS := $(shell find programs/ -type f -iname '*.c')
TARGETS := $(PROGRAMS:.c=.out)

all: $(TARGETS)

%.out: %.c lib/error.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

lib/%.o: lib/%.c include/apue.h
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

clean:
	rm -f $(shell find . -type f -iname '*.o' -or -iname '*.out')
