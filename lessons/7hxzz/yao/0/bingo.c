#include <stdio.h>

void bingo(){
	system("/bin/sh");
}

int main(){
	char buffer[0x40] = {0};
	printf("Pwnme : ");
	read(0, buffer, 0xFF);
	printf("%s", buffer);
	return 0;
}
