#include <stdio.h>

int main(int argc, char* argv[]){
	char buffer[64] = {0};
	gets(buffer);
	printf(buffer);
	return 0;
}

