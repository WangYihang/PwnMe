#include <string.h>

int main(int argc, char *argv[]){
	char buffer[64] = {0};
	printf("Input : \n");
	read(0, buffer, 0xFF);
	printf("[Rright] : \n");
	printf("%s", buffer);
	printf("[Wrong] : \n");
	printf(buffer);
	return 0;
}
