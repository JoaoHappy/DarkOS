[BITS 16]
[ORG 0x7C00] ; origem do endereço do boot da bios

call boot
jmp $ ; trava na chamada
boot:
    mov ah, 0eh ; função de exibir caracter
    mov al, 44h  ; d
    int 10h ; chamada de interrupção de vídeo
    mov al, 41h ; a
    int 10h
    mov al, 52h ; r
    int 10h
    mov al, 4bh ; k
    int 10h
    ret

times 510 - ($-$$) db 0
dw 0xAA55