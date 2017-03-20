#include <stdio.h>

int isPrintable(char ch){
	return (ch > 32 && ch < 127);
}

int isNumber(char ch){
	return (ch >= '0' && ch <= '9');
}

int isLetter(char ch){
	return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

char getByteH(int number){
	return (number << 0 ) >> 24;
}

char getByteMH(int number){
	return (number << 8) >> 24;
}

char getByteML(int number){
	return (number << 16) >> 24;
}

char getByteL(int number){
	return (number << 24) >> 24;
}


int build(char byteH, char byteMH, char byteML, char byteL){
	return ((byteH << 24) + (byteMH << 16) + (byteML << 8) + (byteL << 0));
}


int main(){
	// int target = 0x31c95168;
	int target = 0x11424344;
	int eax = 0;
	char byteH = getByteH(target);
	char byteMH = getByteMH(target);
	char byteML = getByteML(target);
	char byteL = getByteL(target);
	printf("[%c][%c][%c][%c]\n", byteH, byteMH, byteML, byteL);
	printf("[%x][%x][%x][%x]\n", byteH, byteMH, byteML, byteL);
	if (!isLetter(byteH)){
		printf("最高位非字母");
		// 如果不是
		// 计算差距 . 然后用字母填充
		printf("[0x%x] 不是字母 , 需要 eax(为 0 ) 减去 [0x%x] - [0x%x] 的范围才可以\n", byteH, byteH + 0xFF - 'Z', byteH + 0xFF - 'A');
	}
	if (!isLetter(byteMH)){
		printf("中高位非字母");
	}
	if (!isLetter(byteML)){
		printf("中低位非字母");
	}
	if (!isLetter(byteL)){
		printf("最低位非字母");
	}
}
