.model small
.stack 100
.data
    tb1 db 'Ban ten la gi?$'
    tb2 db 'Toi ten la $'
    name db 50 dup<'$'>
    crlf db 13, 10, '$'

.code
Main Proc
    mov ax, @data
    mov ds, ax

    lea dx, tb1
    mov ah, 9
    int 21h

    ; mov cx, 14
    lea si, name
.loop: 
    mov ah, 1
    int 21h

    cmp al, 13
    je .break

    mov [si], al
    inc si
    jmp .loop

.break:
mov byte ptr [si], '$'
lea dx, crlf
mov ah, 9
int 21h
lea dx, tb2
mov ah, 9
int 21h
lea si, name
.show:
    mov ah, 2
    int 21h

    cmp [si], '$'
    je .break2

    inc si
    jmp .show

.break2:
    mov ah, 4ch
    int 21h
Main Endp
END Main 
; org 100h
;
; mov ah, 1
; int 21h
;
; mov dl, al
; mov ah, 2
; int 21h
;
; mov ah, 4ch
; int 21h
;
; ret
