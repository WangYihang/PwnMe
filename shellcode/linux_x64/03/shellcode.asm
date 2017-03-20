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
		xor rsi,rsi
		xor rdx,rdx
		xor rax,rax
		mov al, 59
		syscall
		; exit
		; xor rdi, rdi
		mov al, 60
		syscall
	joker:
		call main
	string:
		db '/bin/sh', 0
