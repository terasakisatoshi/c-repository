Run assembly programming

# Mac User

```
$ docker build -t assm .
$ cat run.sh
docker run --rm -it -v $PWD:/work -w /work assm make
$ bash run.sh
nasm -felf64 hello.asm -o hello.o
ld hello.o -o hello
./hello
Hello World
```

# Ubuntu User

```
$ make
nasm -felf64 hello.asm -o hello.o
ld hello.o -o hello
./hello
Hello World
```