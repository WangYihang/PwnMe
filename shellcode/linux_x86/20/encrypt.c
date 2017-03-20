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
		int RIGHT_A = 0x7f7f7f7f;
		int LEFT_A = 0x20202020;
		int RIGHT_B = 0x7f7f7f7f;
		int LEFT_B = 0x20202020;
		int RIGHT_C = 0x7f7f7f7f;
		int LEFT_C = 0x20202020;

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


		int a = LEFT_A + (RIGHT_A - LEFT_A) / 2;
		int b = LEFT_B + (RIGHT_B - LEFT_B) / 2;
		int c = LEFT_C + (RIGHT_C - LEFT_C) / 2;

		int times = 0;

		int *pointer;

		while(1){
				if (times++ > MAX_TIMES){break;}
				printf("[TIMES] : [%d]\n", times);

				// printf("[0x%8x] [0x%8x] [0x%8x]\n", a, b, c);

				int temp = (a + b + c) % 0x100000000;
				// printf("[%x] <--> [%x]", temp, target);

				if (temp > target){
						// printf("大于了\n");
						pointer = getMAX_ABC(&a, &b, &c);
						if (pointer == &a){

								// 这里不能简单二分
								// 需要先找出四个字节中最大的 , 然后将其二分
								char *A_a = (&a + 0); // 这里也不能直接使用 pointer 这个指针 , 因为指针运算是以其自身尺寸(4 Bytes)作为单位的
								char *A_b = (&a + 1);
								char *A_c = (&a + 2);
								char *A_d = (&a + 3);
								char *A_MAX = getMAX(A_a, A_b, A_c, A_d);
								if (A_MAX == A_a){
										RIGHT_A_a = *A_MAX;
										*A_MAX = LEFT_A_a + (RIGHT_A_a - LEFT_A_a) / 2;
								}else if (A_MAX == A_b){
										RIGHT_A_b = *A_MAX;
										*A_MAX = LEFT_A_b + (RIGHT_A_b - LEFT_A_b) / 2;
								}else if (A_MAX == A_c){
										RIGHT_A_c = *A_MAX;
										*A_MAX = LEFT_A_c + (RIGHT_A_c - LEFT_A_c) / 2;
								}else if (A_MAX == A_d){
										RIGHT_A_d = *A_MAX;
										*A_MAX = LEFT_A_d + (RIGHT_A_d - LEFT_A_d) / 2;
								}else{
								
								}
								// printf("[NUMBER_A][MAX] -> a , [] = %8x\n", *a_max);
						}else if (pointer == &b){
								char *B_a = (&b + 0); // 这里也不能直接使用 pointer 这个指针 , 因为指针运算是以其自身尺寸(4 Bytes)作为单位的
								char *B_b = (&b + 1);
								char *B_c = (&b + 2);
								char *B_d = (&b + 3);
								char *B_MAX = getMAX(B_a, B_b, B_c, B_d);
								if (B_MAX == B_a){
										RIGHT_B_a = *B_MAX;
										*B_MAX = LEFT_B_a + (RIGHT_B_a - LEFT_B_a) / 2;
								}else if (B_MAX == B_b){
										RIGHT_B_b = *B_MAX;
										*B_MAX = LEFT_B_b + (RIGHT_B_b - LEFT_B_b) / 2;
								}else if (B_MAX == B_c){
										RIGHT_B_c = *B_MAX;
										*B_MAX = LEFT_B_c + (RIGHT_B_c - LEFT_B_c) / 2;
								}else if (B_MAX == B_d){
										RIGHT_B_d = *B_MAX;
										*B_MAX = LEFT_B_d + (RIGHT_B_d - LEFT_B_d) / 2;
								}else{
								
								}
						}else if (pointer == &c){
								char *C_a = (&c + 0); // 这里也不能直接使用 pointer 这个指针 , 因为指针运算是以其自身尺寸(4 Bytes)作为单位的
								char *C_b = (&c + 1);
								char *C_c = (&c + 2);
								char *C_d = (&c + 3);
								char *C_MAX = getMAX(C_a, C_b, C_c, C_d);
								if (C_MAX == C_a){
										RIGHT_C_a = *C_MAX;
										*C_MAX = LEFT_C_a + (RIGHT_C_a - LEFT_C_a) / 2;
								}else if (C_MAX == C_b){
										RIGHT_C_b = *C_MAX;
										*C_MAX = LEFT_C_b + (RIGHT_C_b - LEFT_C_b) / 2;
								}else if (C_MAX == C_c){
										RIGHT_C_c = *C_MAX;
										*C_MAX = LEFT_C_c + (RIGHT_C_c - LEFT_C_c) / 2;
								}else if (C_MAX == C_d){
										RIGHT_C_d = *C_MAX;
										*C_MAX = LEFT_C_d + (RIGHT_C_d - LEFT_C_d) / 2;
								}else{
								
								}
						}else{
							printf("指针异常.");
							exit(1);
						}
				}else if (temp < target){
						pointer = getMIN_ABC(&a, &b, &c);
						if (pointer == &a){
								printf("MIN -> A , [A] = %8x\n", *pointer);
								LEFT_A = a;
								a = LEFT_A + (RIGHT_A - LEFT_A) / 2;
						}else if (pointer == &b){
								printf("MIN -> B , [B] = %8x\n", *pointer);
								LEFT_B = *pointer;
								*pointer = LEFT_B + (RIGHT_B - LEFT_B) / 2;
						}else if (pointer == &c){
								printf("MIN -> B , [B] = %8x\n", *pointer);
								LEFT_C = *pointer;
								*pointer = LEFT_C + (RIGHT_C - LEFT_C) / 2;
						}else{
							printf("指针异常.");
							exit(1);
						}

				}else{
						printf("[FOUND] : [0x%8x] [0x%8x] [0x%8x]\n", a, b, c);
						printf("[TIMES] : [%d]\n", times);
						break;
				}	
		}
}

int main(){	
		search(0x5899cd80, 0x20, 0x7f, 0xFF);
		// printf("%8x", sum(0x12, 0x23, 0x43, 0xff));
		return 0;
}
