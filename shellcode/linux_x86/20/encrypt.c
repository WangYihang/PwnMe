#include <stdlib.h>
#include <stdio.h>

int *getMAX_ABC(int *a, int *b, int *c){
		int *MAX = a;
		if (*b > *MAX){
				MAX = b;
		}
		if (*c > *MAX){
				MAX = c;
		}
		return MAX;
}


int *getMIN_ABC(int *a, int *b, int *c){
		int *MIN = a;
		if (*b < *MIN){
				MIN = b;
		}
		if (*c < *MIN){
				MIN = c;
		}
		return MIN;
}



char *getMAX(char *a, char *b, char *c, char *d){
		char *MAX = a;
		if (*b > *MAX){
				MAX = b;
		}
		if (*c > *MAX){
				MAX = c;
		}
		if (*d > *MAX){
				MAX = d;
		}
		return MAX;
}

char *getMIN(char *a, char *b, char *c, char *d){
		char *MIN = a;
		if (*b < *MIN){
				MIN = b;
		}
		if (*c < *MIN){
				MIN = c;
		}
		if (*d < *MIN){
				MIN = d;
		}
		return MIN;
}

int sum(char a, char b, char c, char d){
		return (a * 0x1000000 + b * 0x10000 + c * 0x100 + d);
}

void search(int target, char LEFT, char RIGHT, int MAX_TIMES){

		char LEFT_A_a = 0x20;
		char LEFT_A_b = 0x20;
		char LEFT_A_c = 0x20;
		char LEFT_A_d = 0x20;
		char RIGHT_A_a = 0x7f;
		char RIGHT_A_b = 0x7f;
		char RIGHT_A_c = 0x7f;
		char RIGHT_A_d = 0x7f;

		char LEFT_B_a = 0x20;
		char LEFT_B_b = 0x20;
		char LEFT_B_c = 0x20;
		char LEFT_B_d = 0x20;
		char RIGHT_B_a = 0x7f;
		char RIGHT_B_b = 0x7f;
		char RIGHT_B_c = 0x7f;
		char RIGHT_B_d = 0x7f;

		char LEFT_C_a = 0x20;
		char LEFT_C_b = 0x20;
		char LEFT_C_c = 0x20;
		char LEFT_C_d = 0x20;
		char RIGHT_C_a = 0x7f;
		char RIGHT_C_b = 0x7f;
		char RIGHT_C_c = 0x7f;
		char RIGHT_C_d = 0x7f;


		int a = 0x4f4f4f4f;
		int b = 0x4f4f4f4f;
		int c = 0x4f4f4f4f;


		int *pointer;
		int counter = 0;

		while(counter++ < 0xFF){

				printf("[0x%8x] [0x%8x] [0x%8x]\n", a, b, c);

				unsigned int temp = (a + b + c) % (0x100000000);


				if (temp > target){
						printf("[%x] > [%x]\n", temp, target);
						pointer = getMAX_ABC(&a, &b, &c);
						if (pointer == &a){
								// 这里不能简单二分
								// 需要先找出四个字节中最大的 , 然后将其二分
								char _A_a = (char)(a >> 24); // 最高位字节
								char _A_b = (char)(a >> 16);
								char _A_c = (char)(a >> 8);
								char _A_d = (char)(a >> 0);
								char *A_a = &_A_a;
								char *A_b = &_A_b;
								char *A_c = &_A_c;
								char *A_d = &_A_d;
								char *A_MAX = getMAX(A_a, A_b, A_c, A_d);
								if (A_MAX == A_a){
										RIGHT_A_a = *A_MAX;
										*A_MAX = LEFT_A_a + (RIGHT_A_a - LEFT_A_a) / 2;
										printf("[%d] ----- [%d]", LEFT_A_a, RIGHT_A_a);
								}else if (A_MAX == A_b){
										RIGHT_A_b = *A_MAX;
										*A_MAX = LEFT_A_b + (RIGHT_A_b - LEFT_A_b) / 2;
										printf("[%d] ----- [%d]", LEFT_A_b, RIGHT_A_b);
								}else if (A_MAX == A_c){
										RIGHT_A_c = *A_MAX;
										*A_MAX = LEFT_A_c + (RIGHT_A_c - LEFT_A_c) / 2;
										printf("[%d] ----- [%d]", LEFT_A_c, RIGHT_A_c);
								}else if (A_MAX == A_d){
										RIGHT_A_d = *A_MAX;
										*A_MAX = LEFT_A_d + (RIGHT_A_d - LEFT_A_d) / 2;
										printf("[%d] ----- [%d]", LEFT_A_d, RIGHT_A_d);
								}else{

								}
								// 重新构建 a
								a = _A_a * 0x1000000 + _A_b * 0x10000 + _A_c * 0x100 + _A_d;
								// printf("[NUMBER_A][MAX] -> a , [] = %8x\n", *a_max);
						}else if (pointer == &b){
								char _B_a = (char)(b >> 24); // 最高位字节
								char _B_b = (char)(b >> 16);
								char _B_c = (char)(b >> 8);
								char _B_d = (char)(b >> 0);
								char *B_a = &_B_a;
								char *B_b = &_B_b;
								char *B_c = &_B_c;
								char *B_d = &_B_d;
								char *B_MAX = getMAX(B_a, B_b, B_c, B_d);
								if (B_MAX == B_a){
										RIGHT_B_a = *B_MAX;
										*B_MAX = LEFT_B_a + (RIGHT_B_a - LEFT_B_a) / 2;
										printf("[%d] ----- [%d]", LEFT_B_a, RIGHT_B_a);
								}else if (B_MAX == B_b){
										RIGHT_B_b = *B_MAX;
										*B_MAX = LEFT_B_b + (RIGHT_B_b - LEFT_B_b) / 2;
										printf("[%d] ----- [%d]", LEFT_B_b, RIGHT_B_b);
								}else if (B_MAX == B_c){
										RIGHT_B_c = *B_MAX;
										*B_MAX = LEFT_B_c + (RIGHT_B_c - LEFT_B_c) / 2;
										printf("[%d] ----- [%d]", LEFT_B_c, RIGHT_B_c);
								}else if (B_MAX == B_d){
										RIGHT_B_d = *B_MAX;
										*B_MAX = LEFT_B_d + (RIGHT_B_d - LEFT_B_d) / 2;
										printf("[%d] ----- [%d]", LEFT_B_d, RIGHT_B_d);
								}else{

								}
								b = _B_a * 0x1000000 + _B_b * 0x10000 + _B_c * 0x100 + _B_d;
						}else if (pointer == &c){
								char _C_a = (char)(c >> 24); // 最高位字节
								char _C_b = (char)(c >> 16);
								char _C_c = (char)(c >> 8);
								char _C_d = (char)(c >> 0);
								char *C_a = &_C_a;
								char *C_b = &_C_b;
								char *C_c = &_C_c;
								char *C_d = &_C_d;
								char *C_MAX = getMAX(C_a, C_b, C_c, C_d);
								if (C_MAX == C_a){
										RIGHT_C_a = *C_MAX;
										*C_MAX = LEFT_C_a + (RIGHT_C_a - LEFT_C_a) / 2;
										printf("[%d] ----- [%d]", LEFT_C_a, RIGHT_C_a);
								}else if (C_MAX == C_b){
										RIGHT_C_b = *C_MAX;
										*C_MAX = LEFT_C_b + (RIGHT_C_b - LEFT_C_b) / 2;
										printf("[%d] ----- [%d]", LEFT_C_b, RIGHT_C_b);
								}else if (C_MAX == C_c){
										RIGHT_C_c = *C_MAX;
										*C_MAX = LEFT_C_c + (RIGHT_C_c - LEFT_C_c) / 2;
										printf("[%d] ----- [%d]", LEFT_C_c, RIGHT_C_c);
								}else if (C_MAX == C_d){
										RIGHT_C_d = *C_MAX;
										*C_MAX = LEFT_C_d + (RIGHT_C_d - LEFT_C_d) / 2;
										printf("[%d] ----- [%d]", LEFT_C_d, RIGHT_C_d);
								}else{

								}
								c = _C_a * 0x1000000 + _C_b * 0x10000 + _C_c * 0x100 + _C_d;
						}else{
								printf("指针异常.");
								exit(1);
						}
				}else if (temp < target){
						printf("[%x] < [%x]\n", temp, target);
						pointer = getMIN_ABC(&a, &b, &c);
						if (pointer == &a){
								char _A_a = (char)(a >> 24); // 最高位字节
								char _A_b = (char)(a >> 16);
								char _A_c = (char)(a >> 8);
								char _A_d = (char)(a >> 0);
								char *A_a = &_A_a;
								char *A_b = &_A_b;
								char *A_c = &_A_c;
								char *A_d = &_A_d;
								char *A_MIN = getMIN(A_a, A_b, A_c, A_d);
								if (A_MIN == A_a){
										LEFT_A_a = *A_MIN;
										*A_MIN = LEFT_A_a + (RIGHT_A_a - LEFT_A_a) / 2;
										printf("[%d] ----- [%d]", LEFT_A_a, RIGHT_A_a);
								}else if (A_MIN == A_b){
										LEFT_A_b = *A_MIN;
										*A_MIN = LEFT_A_b + (RIGHT_A_b - LEFT_A_b) / 2;
										printf("[%d] ----- [%d]", LEFT_A_b, RIGHT_A_b);
								}else if (A_MIN == A_c){
										LEFT_A_c = *A_MIN;
										*A_MIN = LEFT_A_c + (RIGHT_A_c - LEFT_A_c) / 2;
										printf("[%d] ----- [%d]", LEFT_A_c, RIGHT_A_c);
								}else if (A_MIN == A_d){
										LEFT_A_d = *A_MIN;
										*A_MIN = LEFT_A_d + (RIGHT_A_d - LEFT_A_d) / 2;
										printf("[%d] ----- [%d]", LEFT_A_d, RIGHT_A_d);
								}else{

								}
								a = _A_a * 0x1000000 + _A_b * 0x10000 + _A_c * 0x100 + _A_d;
						}else if (pointer == &b){
								char _B_a = (char)(b >> 24); // 最高位字节
								char _B_b = (char)(b >> 16);
								char _B_c = (char)(b >> 8);
								char _B_d = (char)(b >> 0);
								char *B_a = &_B_a;
								char *B_b = &_B_b;
								char *B_c = &_B_c;
								char *B_d = &_B_d;
								char *B_MIN = getMIN(B_a, B_b, B_c, B_d);
								if (B_MIN == B_a){
										LEFT_B_a = *B_MIN;
										*B_MIN = LEFT_B_a + (RIGHT_B_a - LEFT_B_a) / 2;
										printf("[%d] ----- [%d]", LEFT_B_a, RIGHT_B_a);
								}else if (B_MIN == B_b){
										LEFT_B_b = *B_MIN;
										*B_MIN = LEFT_B_b + (RIGHT_B_b - LEFT_B_b) / 2;
										printf("[%d] ----- [%d]", LEFT_B_b, RIGHT_B_b);
								}else if (B_MIN == B_c){
										LEFT_B_c = *B_MIN;
										*B_MIN = LEFT_B_c + (RIGHT_B_c - LEFT_B_c) / 2;
										printf("[%d] ----- [%d]", LEFT_B_c, RIGHT_B_c);
								}else if (B_MIN == B_d){
										LEFT_B_d = *B_MIN;
										*B_MIN = LEFT_B_d + (RIGHT_B_d - LEFT_B_d) / 2;
										printf("[%d] ----- [%d]", LEFT_B_d, RIGHT_B_d);
								}else{

								}
								b = _B_a * 0x1000000 + _B_b * 0x10000 + _B_c * 0x100 + _B_d;
						}else if (pointer == &c){
								char _C_a = (char)(c >> 24); // 最高位字节
								char _C_b = (char)(c >> 16);
								char _C_c = (char)(c >> 8);
								char _C_d = (char)(c >> 0);
								char *C_a = &_C_a;
								char *C_b = &_C_b;
								char *C_c = &_C_c;
								char *C_d = &_C_d;
								char *C_MIN = getMIN(C_a, C_b, C_c, C_d);
								if (C_MIN == C_a){
										LEFT_C_a = *C_MIN;
										*C_MIN = LEFT_C_a + (RIGHT_C_a - LEFT_C_a) / 2;
										printf("[%d] ----- [%d]", LEFT_C_a, RIGHT_C_a);
								}else if (C_MIN == C_b){
										LEFT_C_b = *C_MIN;
										*C_MIN = LEFT_C_b + (RIGHT_C_b - LEFT_C_b) / 2;
										printf("[%d] ----- [%d]", LEFT_C_b, RIGHT_C_b);
								}else if (C_MIN == C_c){
										LEFT_C_c = *C_MIN;
										*C_MIN = LEFT_C_c + (RIGHT_C_c - LEFT_C_c) / 2;
										printf("[%d] ----- [%d]", LEFT_C_c, RIGHT_C_c);
								}else if (C_MIN == C_d){
										LEFT_C_d = *C_MIN;
										*C_MIN = LEFT_C_d + (RIGHT_C_d - LEFT_C_d) / 2;
										printf("[%d] ----- [%d]", LEFT_C_d, RIGHT_C_d);
								}else{

								}
								c = _C_a * 0x1000000 + _C_b * 0x10000 + _C_c * 0x100 + _C_d;
						}else{
								printf("指针异常.");
								exit(1);
						}

				}else{
						printf("[%x] = [%x]", temp, target);
						printf("[FOUND] : [0x%8x] [0x%8x] [0x%8x]\n", a, b, c);
						break;
				}	
		}
}

int main(){	
		search(0x87654321, 0x20, 0x7f, 0xFF);
		// printf("%8x", sum(0x12, 0x23, 0x43, 0xff));
		return 0;
}
