all: main

libmypi.so: ../selfContained/calcpi.c ../selfContained/calcgcd.c
	$(CC) -shared -o $@ $^

main: main.c libmypi.so
	$(CC) -o $@ $^

clean:
	rm -f libmypi.so
	rm -f main