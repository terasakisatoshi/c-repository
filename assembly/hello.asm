; hello.asm

global _start


section .data
str_hello   db  "Hello World", 10


section .text
_start:
    mov rax, 1
    mov rdi, 1
    mov rsi, str_hello
    mov rdx, 14
    syscall                 ; Call system call.
    mov rax, 60
    xor rdi, rdi
    syscall                 ; Call system call.