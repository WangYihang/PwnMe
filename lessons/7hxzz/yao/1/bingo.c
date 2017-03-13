#include <stdio.h>

int main(){
	char buf[50] = {0};
	printf("I am at %p\nWhere are you?\n", buf);
	fflush(stdout);
	read(0, buf, 0xff);
	printf("I got you! %s\n", buf);
	return 0;
}
