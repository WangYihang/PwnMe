#include <stdio.h>

int *getMAX(int *a, int *b, int *c){
	int *MAX = a;
	if (*b > *MAX){
		MAX = b;
	}
	if (*c > *MAX){
		MAX = c;
	}
	return MAX;
}

int *getMIN(int *a, int *b, int *c){
	int *MIN = a;
	if (*b < *MIN){
		MIN = b;
	}
	if (*c < *MIN){
		MIN = c;
	}
	return MIN;
}

int search(int target){
	int RIGHT_A = 0x7f7f7f7f;
	int LEFT_A = 0x20202020;
	int RIGHT_B = 0x7f7f7f7f;
	int LEFT_B = 0x20202020;
	int RIGHT_C = 0x7f7f7f7f;
	int LEFT_C = 0x20202020;
	int *pointer;
	int a = LEFT_A + (RIGHT_A - LEFT_A);
	int b = LEFT_B + (RIGHT_B - LEFT_B);
	int c = LEFT_C + (RIGHT_C - LEFT_C);
	int times = 0;
	int MAX_TIMES = 100;
	while(1){
			printf("[A] = [%8x], [B] = [%8x], [C] = [%8x]\n", a, b, c);
			if (times++ > MAX_TIMES){break;}
			printf("[TIMES] : [%d]\n", times);
			if ((a + b + c) > target){
				pointer = getMAX(&a, &b, &c);
				if (pointer == &a){
					printf("MAX -> A , [A] = %8x\n", *pointer);
					RIGHT_A = *pointer;
					*pointer = LEFT_A + (RIGHT_A - LEFT_A) / 2;
				}
				if (pointer == &b){
					printf("MAX -> B , [B] = %8x\n", *pointer);
					RIGHT_B = *pointer;
					*pointer = LEFT_B + (RIGHT_B - LEFT_B) / 2;
				}
				if (pointer == &c){
					printf("MAX -> C , [C] = %8x\n", *pointer);
					RIGHT_C = *pointer;
					*pointer = LEFT_C + (RIGHT_C - LEFT_C) / 2;
				}

			}else if((a + b + c) < target){
				pointer = getMIN(&a, &b, &c);
				if (pointer == &a){
					printf("MIN -> A , [A] = %8x\n", *pointer);
					LEFT_A = a;
					a = LEFT_A + (RIGHT_A - LEFT_A) / 2;
				}
				if (pointer == &b){
					printf("MIN -> B , [B] = %8x\n", *pointer);
					LEFT_B = *pointer;
					*pointer = LEFT_B + (RIGHT_B - LEFT_B) / 2;
				}
				if (pointer == &c){
					printf("MIN -> B , [B] = %8x\n", *pointer);
					LEFT_C = *pointer;
					*pointer = LEFT_C + (RIGHT_C - LEFT_C) / 2;
				}
			
			}else{
				printf("[FOUND] : [%8x] [%8x] [%8x]\n", a, b, c);
			}	
	}
}

int main(){
		
	search(0x12345678);
	return 0;
}
