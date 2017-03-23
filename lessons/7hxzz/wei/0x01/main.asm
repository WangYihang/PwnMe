global _start
	_start:
		pop eax
		push 0804A020H
		sub eax, 84
		mov [esp - 4], eax
		add eax, 19H
		push eax
		jmp eax
