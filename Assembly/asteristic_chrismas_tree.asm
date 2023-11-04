; the code shoud print
; something like this:
;      *
;     ***
;    *****
;   *******
;  *********
; ***********

SIZE equ 10 ;; size of the tree in lines

section .data
    space      db 0x20, 0x00
    asteristic db 0x2A, 0x00
    newline    db 0x0A, 0x00

section .bss
    space_times       resb 10
    asteristic_times  resb 10

section .text
global _start
_start:
    mov byte [space_times], SIZE
    mov byte [asteristic_times], 1

_start_loop_tree:
    cmp qword [space_times], 0
    je _end_loop_tree
    mov rsi, space
    mov rdi, qword [space_times]
    call _print_times
    mov rsi, asteristic
    mov rdi, qword [asteristic_times]
    call _print_times
    mov rdi, newline
    call _print_str
    dec byte [space_times]
    add byte [asteristic_times], 2
    jmp _start_loop_tree

_end_loop_tree:
    mov eax, 60
    xor edi, edi
    syscall

_count_char:
    xor ecx, ecx

_start_loop_counter:
    cmp byte [edi+ecx], 0x0a
    je _end_loop_counter
    cmp byte [edi+ecx], 0x00
    je _end_loop_counter
    inc ecx
    jmp _start_loop_counter

_end_loop_counter:
    inc ecx
    mov eax, ecx
    ret

_print_str:
    push rbp
    mov rbp, rsp
    sub rsp, 16
    mov qword [rbp-8], rdi
    ; calling next function with same rdi
    call _count_char
    mov edx, eax
    mov rsi, qword [rbp-8]
    mov edi, 1
    mov eax, 1
    syscall
    leave
    ret

_print_times:
    push rbp
    mov rbp, rsp
    sub rsp, 16
    mov qword [rbp-8], rdi
    mov qword [rbp-16], rsi
    xor ecx, ecx

_start_loop_print_times:
    cmp rcx, qword [rbp-8]
    je _end_loop_print_times
    inc ecx
    push rcx
    mov rdi, qword [rbp-16]
    call _print_str
    pop rcx
    jmp _start_loop_print_times

_end_loop_print_times:
    leave
    ret