#include <stdio.h>
#include <string.h>

int main(){
	char buffer[16] = {0};
	char *words = "Dancing in shackles, Right?\n";
	write(1, words, strlen(words));
	read(0, buffer, 0xFF);
	return 0;
}
