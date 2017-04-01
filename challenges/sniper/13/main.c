#include <stdio.h>
#include <unistd.h>

int main(){
	char buffer[16] = {0};
	printf("[Input] : \n");
	read(0, buffer, 0xFF);
	printf(buffer);
	return 0;
}
