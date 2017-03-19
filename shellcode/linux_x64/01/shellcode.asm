;section .data
;	string db 'Hello world!',10,0
section .text
global _start
	_start:
		; get string address
		jmp joker
	main:
		; write
		mov rdi, 1
		pop rsi
		mov rdx, 13 ; length of 'Hello world!\n'
		mov rax, 1
		syscall
		; exit
		mov edi, 0
		mov rax, 60
		syscall
	joker:
		call main
	string:
		db 'Hello world!',10 , 0
