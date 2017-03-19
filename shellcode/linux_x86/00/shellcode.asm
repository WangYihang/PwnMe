section .data
	string db 'Hello world!',0
section .text
global _start
	_start:
	; write to stdout
	mov eax, 4
	mov ebx, 1
	mov ecx, string
	mov edx, 13
	int 80H	
	; exit
	mov eax, 1
	mov ebx, 0
	int 80H


