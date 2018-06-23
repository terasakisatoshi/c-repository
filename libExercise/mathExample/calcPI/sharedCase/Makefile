all: main

libmypi.so: ../selfContained/calcpi.c ../selfContained/calcgcd.c
	gcc -shared -o $@ $^

main: main.c libmypi.so
	gcc -o $@ $^

clean:
	rm -f libmypi.so
	rm -f main