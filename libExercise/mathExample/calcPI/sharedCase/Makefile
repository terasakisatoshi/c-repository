all: main

libmypi.dylib: ../selfContained/calcpi.c ../selfContained/calcgcd.c
	$(CC) -shared -o $@ $^

main: main.c libmypi.dylib
	$(CC) -o $@ $^

clean:
	rm -f libmypi.dylib
	rm -f main