section .text

exit:
    xor rdi, rdi
    mov rax, 60
    syscall

string_length:
    xor rax, rax
.loop:
    cmp byte [rdi+rax], 0
    je .end

    inc rax
    jmp .loop
.end:
    ; rax holds the number of chars in string
    ret

print_string:
    push rdi ; save source string pointer
    call string_length
    mov rdx, rax ; passing string length, returned in rax by string_length function

    pop rdi ; return string pointer screwed by string_length function
    mov rsi, rdi ; take string pointer as a source

    mov rax, 1
    mov rdi, 1
    syscall

    ret

print_char:
    push rdi
    mov rdi, rsp
    call print_string
    pop rdi
    ret

print_newline:
    mov rdi, 10
    jmp print_char
    ret

print_uint:
    xor rax, rax
    ret


print_int:
    xor rax, rax
    ret

string_equals:
    xor rax, rax
    ret


read_char:
    xor rax, rax
    ret

read_word:
    ret

; rdi points to a string
; returns rax: number, rdx : length
parse_uint:
    xor rax, rax
    ret

; rdi points to a string
; returns rax: number, rdx : length
parse_int:
    xor rax, rax
    ret


string_copy:
    xor rax, rax
    ret
