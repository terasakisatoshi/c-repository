all:main

libmypi.a: calcgcd.o calcpi.o
	ar r $@ $^

calcgcd.o: ../selfContained/calcgcd.c
	$(CC) -c $^ -o $@

calcpi.o: ../selfContained/calcpi.c
	$(CC) -c $^ -o $@

main: main.c libmypi.a
	$(CC) main.c -L./ -lmypi -o main

clean:
	rm -f *.o
	rm -f *.a