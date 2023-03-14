
CC = gcc
CFLAGS = -Wall -I./include
CFILES = $(wildcard src/*.c)
OBJECTS = $(subst src, build, $(patsubst %.c, %.o, $(CFILES)))

all : bin/main

bin/main : $(OBJECTS)
	$(CC) -o $@ $^

build/%.o : src/%.c include/%.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean : 
	rm bin/main.exe
	rm $(OBJECTS)
