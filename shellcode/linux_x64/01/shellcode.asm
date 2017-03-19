section .data
	string db 'Hello world!',10,0
section .text
global _start
	_start:
		; write
		mov rdi, 1
		mov rsi, string
		mov rdx, 13 ; length of 'Hello world!\n'
		mov rax, 1
		syscall
		; exit
		mov edi, 0
		mov rax, 60
		syscall
