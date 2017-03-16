简介 : 
```
优化上节课的代码
```
环境 : 
```
Linux_x86
```
问题 : 
```
并不是一个完整的 shellcode
因为 shellcode 只是一段数据 , 插入程序就可以执行
因此并不能使用到其他的段
而我们这里使用了 data 段来存储字符串 "/bin//sh"
因此还需要进一步优化
```
参考 :
```
sun@sun:~/pwnme/shellcode/02$ objdump -d shellcode

shellcode:     file format elf32-i386


Disassembly of section .text:

08048080 <_start>:
 8048080:	b0 0b                	mov    $0xb,%al
 8048082:	bb 90 90 04 08       	mov    $0x8049090,%ebx
 8048087:	31 c9                	xor    %ecx,%ecx
 8048089:	31 d2                	xor    %edx,%edx
 804808b:	cd 80                	int    $0x80
```
