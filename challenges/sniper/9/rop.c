#include <stdio.h>
#include <string.h>

int callsystem(){
	system("ls");
}

int main(){
	char buffer[16] = {0};
	printf("[Command] : \n");
	read(0, buffer, 0xFF);
	buffer[strlen(buffer) - 1] = '\0';
	printf("Your command is [%s]\n", buffer);
	printf("Can you execute your command ? \n");
	return 0;
}
