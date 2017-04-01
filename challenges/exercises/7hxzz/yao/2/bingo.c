#include <stdio.h>

int main() {
		char buf[0x50] = {0};
		int *addr = NULL;
		printf("What do you want to know?\n");
		fflush(stdout);
		read(0,&addr,4);
		printf("result: %p\n", *addr);
		printf("Now tell me who you are?\n");
		fflush(stdout);
		read(0,buf,0xff);
		printf("Hello, %s\n",buf);
		return 0;
}
