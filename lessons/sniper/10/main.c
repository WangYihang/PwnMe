#include <stdio.h>

int main(){	
	char buffer[16] = {0};
	printf("Address : %p\n", &buffer);
	read(0, buffer, 0xFF);
	return 0;
}
