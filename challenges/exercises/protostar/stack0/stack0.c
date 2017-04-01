#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	volatile int modified; // volatile 防止编译器对代码进行优化
	/* 按照声明的顺序来排列 , modified 在高地址 , 因此可能会被覆盖
	 * (gdb) p &buffer
	 * $2 = (char (*)[64]) 0xffffd644
	 * (gdb) p &modified
	 * $3 = (volatile int *) 0xffffd684
	 */
	// int modified; // volatile 防止编译器对代码进行优化
	/* 编译器优化 , modified 在低地址 , 溢出的时候不会被覆盖
	 * (gdb) p &modified
	 * $1 = (int *) 0x7fffffffe48c
	 * (gdb) p &buffer
	 * $2 = (char (*)[64]) 0x7fffffffe490
	 */

	/*
	 * 在编译的时候 , 编译器会重新排列变量的布局
	 * 一般情况下 , 字符数组等有可能产生栈溢出的变量会被分配在高地址区域
	 * 这样当栈溢出的时候就不会影响到别的变量
	 */
	char buffer[64];

	modified = 0;
	gets(buffer);

	printf("%x", modified);

	if(modified == 0x1234) {
		printf("you have changed the 'modified' variable\n");
	} else {
		printf("Try again?\n");
	}
}
