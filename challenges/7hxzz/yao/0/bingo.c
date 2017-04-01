#include <stdio.h>

void bingo(){
	system("/bin/sh");
}

int main() {
	char buf[10] = {0};
	puts("What's your name:");
	read(0,buf,0xff);
	printf("Hello %s",buf);
	return 0;
}
