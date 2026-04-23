CC = gcc
CFLAGS = -std=c99 -g -Og -Wall -I./include
LDFLAGS =

SRCS := (shell find . -maxdepth 1 -type f -iname '*.c')

all: ls.out

programs/intro/%.o: %.c lib/error.o
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

lib/error.o: lib/error.c include/apue.h
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

lib/errorlog.o: lib/errorlog.c include/apue.h
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

clean:
	rm -f $(shell find . -type f -iname '*.o' -or -iname '*.out')
