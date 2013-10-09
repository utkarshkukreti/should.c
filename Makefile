CFLAGS=-Wall -Wextra -pedantic -std=c99 -Iinclude

default: example

example:
	mkdir -p bin
	$(CC) $(CFLAGS) -o bin/example example.c
	bin/example

clean:
	rm bin/example
