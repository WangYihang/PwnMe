;section .data
;	string db 'Hello world!',10,0
section .text
global _start
	_start:
		; get string address
		jmp joker
	main:
		; exec
		pop rdi
		mov rsi, 0
		mov rdx, 0
		mov rax, 59
		syscall
		; exit
		mov edi, 0
		mov rax, 60
		syscall
	joker:
		call main
	string:
		db '/bin/sh', 0
