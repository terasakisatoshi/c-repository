all: run

run: hello.asm
	nasm -felf64 hello.asm -o hello.o
	ld hello.o -o hello
	./hello

clean:
	rm -f hello hello.o
