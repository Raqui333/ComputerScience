;; this app should read the user input
;; then print a message greating it
;; e.g: "Hello <name>, nice to meet ya!"

section .data
    prompt db "What is your name? ", 0x00
    greating db "Hello *, nice to meet ya!", 0x0a, 0x00
    BUF_SIZE equ 64

section .bss
    buf resb BUF_SIZE
    tmp resb BUF_SIZE

section .text
global _start
_start:
    ;; print prompt
    mov rdi, prompt
    call print_str

    ;; read stdin
    mov rdi, buf
    mov rsi, BUF_SIZE
    call read_input

    ;; print until especified char
    mov rdi, greating
    mov rsi, 0x2a
    call print_until

    ;; print inputed string
    mov rdi, buf
    call print_str

    ;; print until null-terminated
    xor rcx, rcx

start_loop_count_until_asterix:
    cmp byte [greating+rcx], 0x2a
    je end_loop_count_until_asterix
    inc rcx
    jmp start_loop_count_until_asterix

end_loop_count_until_asterix:
    lea rdi, byte [greating+rcx+1]
    mov rsi, 0x00
    call print_until

    ;; exit sucess
    mov rax, 0x3c
    xor rdi, rdi
    syscall

count_char:
    xor rcx, rcx

start_loop_counter:
    cmp byte [rdi+rcx], 0x00
    je end_loop_counter
    inc rcx
    jmp start_loop_counter

end_loop_counter:
    mov rax, rcx
    ret

print_str:
    call count_char
    mov rdx, rax
    mov rsi, rdi
    mov rdi, 1
    mov rax, 1
    syscall
    ret

read_input:
    mov rdx, rsi
    mov rsi, rdi
    xor rdi, rdi
    xor rax, rax
    syscall

    ;; remove the newline at the end of input
    mov rdi, rsi
    call count_char
    mov byte [rdi+rax-1], 0x00
    ret

;; print until especified char or null-terminated
print_until:
    xor rcx, rcx

start_loop_print_until:
    mov al, byte [rdi+rcx]
    cmp al, sil
    je end_loop_print_until
    mov byte[tmp+rcx], al
    inc rcx
    jmp start_loop_print_until

end_loop_print_until:
    mov rdi, tmp
    call print_str
    ret
