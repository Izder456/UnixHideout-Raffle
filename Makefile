# BSD-compatible Makefile for "The Unixhideout Laptop main" program

CC=cc
CFLAGS=-Wall -Wextra -std=c99

all: main

main: main.o
	$(CC) $(CFLAGS) -o main main.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f main main.o
