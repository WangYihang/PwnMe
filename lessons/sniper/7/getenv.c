#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	if (argc != 2){
		printf("Usage : \n");
		printf("\t getenv [ENV]\n");
		exit(1);
	}
	char *buffer;
	buffer = getenv(argv[1]);
	if (buffer == NULL){
		printf("[%s] not found.\n", argv[1]);
	}else{
		printf("[VALUE] : \n[%s]\n", buffer);
		printf("[ADDRESS] : \n[%p]\n", buffer);
	}
	return 0;
}
