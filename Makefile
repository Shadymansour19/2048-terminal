CC = gcc
CFLAGS = -Wall -g
LIBS = -lncurses


2048-terminal: src/* 
	$(CC) $(CFLAGS) src/* $(LIBS) -o 2048-terminal

clean:
	rm -f 2048-terminal

run: 2048-terminal
	./2048-terminal

install: 2048-terminal
	mkdir -p $(DESTDIR)/usr/games
	cp 2048-terminal $(DESTDIR)/usr/games/