#include <stdio.h>
#include <unistd.h>

int main(){
	char buffer[8] = {0};	
	printf("[Buffer] -> %p\n", buffer);
	printf("[Username] : \n");
	read(0, buffer, 0x20);
	printf("%s", buffer);
	printf("[Password] : \n");
	read(0, buffer, 0x20);
	printf("%s", buffer);
	return 0;
}
