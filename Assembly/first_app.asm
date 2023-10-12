;; my first well know code in assembly
;; this program get 2 1-bytesize number from stdin
;; and then sum both to another 1-bytesize number
;; which means it only sum up to 9 (4 + 5) 

section .data
    prompt db "> ", 0x00

section .bss
    num1 resb 2
    num2 resb 2
    resu resb 2

section .text
global _start
_start:
    ;; print prompt for 1st number
    mov rdi, prompt
    mov rsi, 2
    call print_it

    ;; read 1st number
    mov rdi, num1
    mov rsi, 2
    call read_it

    ;; print prompt for 2nd number
    mov rdi, prompt
    mov rsi, 2
    call print_it

    ;; read 2nd number
    mov rdi, num2
    mov rsi, 2
    call read_it

    ;; convert both number to int
    ;; because from it is stdin 0x??0a
    mov rdi, num1
    call to_int
    mov rdi, num2
    call to_int

    ;; sum both and store rusult to
    ;; var resu
    mov al, byte [num1]
    add al, byte [num2]
    mov byte [resu], al

    ;; convert var resu to string
    mov rdi, resu
    call to_str

    mov rdi, resu
    mov byte [rdi+1], 0x0a ;; newline for output
    mov rsi, 2
    call print_it

    ;; exit
    mov rax, 60
    xor rdi, rdi
    syscall

print_it:
    mov rax, 1
    mov rdx, rsi
    mov rsi, rdi
    mov rdi, 1
    syscall
    ret

read_it:
    mov rax, 0
    mov rdx, rsi
    mov rsi, rdi
    mov rdi, 0
    syscall
    ret

to_int:
    sub byte [rdi+1], 0x0a
    mov al, byte [rdi]
    sub al, 0x30
    mov byte [rdi], al
    ret

to_str:
    mov al, byte [rdi]
    add al, 0x30
    mov byte [rdi], al
    ret