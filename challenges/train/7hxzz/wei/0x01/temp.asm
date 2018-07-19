global _start
	_start:
		pop eax
		sub eax, 84
		push 010H
		push 0804A020H
		push 0
		push eax
		; jmp 08048330H
		jmp [0804A00CH]
