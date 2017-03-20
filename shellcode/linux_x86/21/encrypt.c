#include <stdlib.h>
#include <stdio.h>

struct RESULT_BYTE {
	int overflow; // 进位的个数
	char a;
	char b;
	char c;
};

struct RESULT{
	int result_a;
	int result_b;
	int result_c;
};

char *getMAX(char *a, char *b, char *c){
	char *MAX = a;
	if (*b > *MAX){
		MAX = b;
	}
	if (*c > *MAX){
		MAX = c;
	}
	return MAX;
}

char *getMIN(char *a, char *b, char *c){
	char *MIN = a;
	if (*b < *MIN){
		MIN = b;
	}
	if (*c < *MIN){
		MIN = c;
	}
	return MIN;
}

struct RESULT_BYTE * searchByte(char target, char LEFT, char RIGHT){
	char LEFT_A = LEFT;
	char RIGHT_A = RIGHT;
	char a = LEFT_A + (RIGHT_A - LEFT_A) / 2;

	char LEFT_B = LEFT;
	char RIGHT_B = RIGHT;
	char b = LEFT_B + (RIGHT_B - LEFT_B) / 2;

	char LEFT_C = LEFT;
	char RIGHT_C = RIGHT;
	char c = LEFT_C + (RIGHT_C - LEFT_C) / 2;

	int counter = 0;

	while(counter++ < 0xFF){
		// printf("[TIMES] : [%x]\t", counter);
		// printf("[%d] [%d] [%d]\n", a, b, c);
		char temp = (a + b + c) % 0x100; // 计算和
		char *pointer;
		if (temp > target){
			pointer = getMAX(&a, &b, &c);	
			*pointer = *pointer + 1;
		}else if(temp < target){
			pointer = getMIN(&a, &b, &c);	
			*pointer = *pointer + 1;
		}else{
			struct RESULT_BYTE * result = malloc(sizeof(struct RESULT_BYTE));
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

struct RESULT * search(int target){
	
	struct RESULT * result = malloc(sizeof(struct RESULT));
	char byte_l = (target >> 0) % 0x100;
	char byte_ml = (target >> 8) % 0x100;
	char byte_mh = (target >> 16) % 0x100;
	char byte_h = (target >> 24) % 0x100;
	int overflow = 0;

	struct RESULT_BYTE * result_byte = NULL;
	printf("-------------------------\n");
	printf("Searching : [%d] = [0x%x]\n", byte_l, byte_l);
	result_byte = searchByte(byte_l, 0x20, 0x7f);
	result->result_a = result->result_a + result_byte->a;//
	result->result_b = result->result_b + result_byte->b;//
	result->result_c = result->result_c + result_byte->c;//
	overflow = result_byte->overflow;
	free(result_byte);

	printf("-------------------------\n");
	printf("Searching : [%d] = [0x%x]\n", byte_ml, byte_ml);
	result_byte = searchByte(byte_ml - overflow, 0x20, 0x7f);
	result->result_a = result->result_a + result_byte->a * 0x100;//
	result->result_b = result->result_b + result_byte->b * 0x100;//
	result->result_c = result->result_c + result_byte->c * 0x100;//
	overflow = result_byte->overflow;
	free(result_byte);
	printf("-------------------------\n");
	printf("Searching : [%d] = [0x%x]\n", byte_mh, byte_mh);
	result_byte = searchByte(byte_mh - overflow, 0x20, 0x7f);
	result->result_a = result->result_a + result_byte->a * 0x10000;//
	result->result_b = result->result_b + result_byte->b * 0x10000;//
	result->result_c = result->result_c + result_byte->c * 0x10000;//
	overflow = result_byte->overflow;
	free(result_byte);
	printf("-------------------------\n");
	printf("Searching : [%d] = [0x%x]\n", byte_h, byte_h);
	result_byte = searchByte(byte_h - overflow, 0x20, 0x7f);
	result->result_a = result->result_a + result_byte->a * 0x1000000;//
	result->result_b = result->result_b + result_byte->b * 0x1000000;//
	result->result_c = result->result_c + result_byte->c * 0x1000000;//
	overflow = result_byte->overflow;
	free(result_byte);
	printf("-------------------------\n");
	return result;
}

int main(){
	int target = 0x12345678;
	printf("[Target] : 0x%x\n", target);
	struct RESULT * result = search(target);
	//int a = ;
	//int b = ;
	//int c = ;
	// print
	printf("[FOUND] : \n");
	printf("[0x%x] [0x%x] [0x%x]\n", result->result_a, result->result_b, result->result_c);
	printf("0x%x + 0x%x + 0x%x\n", result->result_a, result->result_b, result->result_c);
	// free
	free(result);
}

// 产生一个问题 :
// C语言在计算立即数的时候的内存是怎么分配的
