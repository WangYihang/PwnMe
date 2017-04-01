global _start
	_start:
		push 0bH
		pop eax
		cdq
		xor ecx, ecx
		; push edx
		push "/sh"
		push "/bin"
		mov ebx, esp
		int 80H
