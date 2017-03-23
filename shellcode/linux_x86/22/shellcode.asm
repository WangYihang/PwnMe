section .data
	ip db "127.0.0.1",0
	port db "2333",0
section .text
global _start
	_start:	
		; env
		mov edx, 0
		; argv
		push port
		push ip
		mov ecx, esp
		; file path
		push edx
		push "//sh"
		push "/bin"
		mov ebx, esp
		; syscall id
		push 0bH
		pop eax
		int 80H
