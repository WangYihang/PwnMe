global _start
	_start:	
		; env
		mov edx, 0
		; argv
		mov ecx, 0
		; file path
		; push edx
		;push "s -a"
		;push "-c l"
		push "/sh"
		push "/bin"
		mov ebx, esp
		; syscall id
		push 0bH
		pop eax
		int 80H
