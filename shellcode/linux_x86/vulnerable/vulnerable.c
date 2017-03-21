#include <stdio.h>

int main(){
	char buffer[8];
	printf("%p\n", &buffer);
	read(0, buffer, 0x1A0);
}
