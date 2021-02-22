[BITS 16]
[ORG 0000h]

jmp Main

BackWidth db 0
BackHeight db 0
Pagination db 0 ; tela 0 

Welcome db "Welcome ao DarkOS", 0 

Main:
    call ConfigSegment ; codigo e os dados ficaram salvos nesse segmento
    call ConfigStack    ; confg da pilha
    call TEXT.SetVideoMode ; modo de texto ativado
    jmp ShowString

ShowString:
    mov dh, 3 ; linha 3 
    mov dl, 2 ; coluna 3
    call MoveCursor ; vau saltar para mover o cursor
    mov si, Welcome ; vai pegar a string welcome des da origem dela
    call DarkString ; vai mostra na tela
    jmp END

ConfigSegment:
    mov ax, es ; aqui ficara guardado o segmento do sistema operacional
    mov ds, ax ; data segment
ret

ConfigStack:
    mov ax, 2D00h   ; endereço da pilha
    mov ss, ax      ; vai armazena o endereço inicial da pilha
    mov sp, 03FEh   ;2D00h:03FEh vai apontar para o endereço de ax
ret

TEXT.SetVideoMode:
    mov ah, 00h  ; entra no modo de video
    mov al, 03h ;modo de texto 80 colunas e 20 linhas
    int 10h
    mov BYTE[BackWidth], 80
    mov BYTE[BackHeight], 20
ret

DarkString:
    mov ah, 09h
    mov bh, [Pagination] ; existe 16 paginação no modo de texto
    mov bl, 30
    mov cx, 1
    mov al, [si]
    print:  ; subrotina
        int 10h
        inc si ;vai apontar pro proximo endereço
        call MoveCursor
        mov ah, 09h
        mov al, [si] ; vai pro proximo caracter
        cmp al, 0 ; chega até a 0 
        jne print
ret

MoveCursor:
    mov ah, 02h ; funcao de cursor
    mov bh, [Pagination] ;
    inc dl 
    int 10h
ret

END:
    jmp $


