global _start
	_start:
		xor eax, eax
		cdq
		push eax
		push "//sh"
		push "/bin"
		mov ebx, esp
		mov al, 0bH
		int 80H
