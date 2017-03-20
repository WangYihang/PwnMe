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



char *getMAX(char *a, char *b, char *c, char *d, char *e, char *f, char *g, char *h, char *i, char *j, char *k, char *l){
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
		if (*e > *MAX){
				MAX = e;
		}
		if (*f > *MAX){
				MAX = f;
		}
		if (*g > *MAX){
				MAX = g;
		}
		if (*h > *MAX){
				MAX = h;
		}
		if (*i > *MAX){
				MAX = i;
		}
		if (*j > *MAX){
				MAX = j;
		}
		if (*k > *MAX){
				MAX = k;
		}
		if (*l > *MAX){
				MAX = l;
		}
		return MAX;
}

char *getMIN(char *a, char *b, char *c, char *d, char *e, char *f, char *g, char *h, char *i, char *j, char *k, char *l){
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
		if (*e < *MIN){
				MIN = e;
		}
		if (*f < *MIN){
				MIN = f;
		}
		if (*g < *MIN){
				MIN = g;
		}
		if (*h < *MIN){
				MIN = h;
		}
		if (*i < *MIN){
				MIN = i;
		}
		if (*j < *MIN){
				MIN = j;
		}
		if (*k < *MIN){
				MIN = k;
		}
		if (*l < *MIN){
				MIN = l;
		}
		return MIN;
}

int sum(char a, char b, char c, char d){
		return (a * 0x1000000 + b * 0x10000 + c * 0x100 + d);
}

void search(int target, char LEFT, char RIGHT, int MAX_TIMES){
		char RIGHT_A = RIGHT;
		char LEFT_A = LEFT;
		char RIGHT_B = RIGHT;
		char LEFT_B = LEFT;
		char RIGHT_C = RIGHT;
		char LEFT_C = LEFT;
		char RIGHT_D = RIGHT;
		char LEFT_D = LEFT;
		char RIGHT_E = RIGHT;
		char LEFT_E = LEFT;
		char RIGHT_F = RIGHT;
		char LEFT_F = LEFT;
		char RIGHT_G = RIGHT;
		char LEFT_G = LEFT;
		char RIGHT_H = RIGHT;
		char LEFT_H = LEFT;
		char RIGHT_I = RIGHT;
		char LEFT_I = LEFT;
		char RIGHT_J = RIGHT;
		char LEFT_J = LEFT;
		char RIGHT_K = RIGHT;
		char LEFT_K = LEFT;
		char RIGHT_L = RIGHT;
		char LEFT_L = LEFT;

		char a = (char)(LEFT_A + (RIGHT_A - LEFT_A) / 2);
		char b = (char)(LEFT_B + (RIGHT_B - LEFT_B) / 2);
		char c = (char)(LEFT_C + (RIGHT_C - LEFT_C) / 2);
		char d = (char)(LEFT_D + (RIGHT_D - LEFT_D) / 2);
		char e = (char)(LEFT_E + (RIGHT_E - LEFT_E) / 2);
		char f = (char)(LEFT_F + (RIGHT_F - LEFT_F) / 2);
		char g = (char)(LEFT_G + (RIGHT_G - LEFT_G) / 2);
		char h = (char)(LEFT_H + (RIGHT_H - LEFT_H) / 2);
		char i = (char)(LEFT_I + (RIGHT_I - LEFT_I) / 2);
		char j = (char)(LEFT_J + (RIGHT_J - LEFT_J) / 2);
		char k = (char)(LEFT_K + (RIGHT_K - LEFT_K) / 2);
		char l = (char)(LEFT_L + (RIGHT_L - LEFT_L) / 2);

		char *pointer;

		int times = 0;

		int AAAA = 0;
		int BBBB = 0;
		int CCCC = 0;

		int *pointer_ABC;

		while(1){
				if (times++ > MAX_TIMES){break;}
				printf("[TIMES] : [%d]\n", times);

				AAAA = sum(a, b, c, d);
				BBBB = sum(e, f, g, h);
				CCCC = sum(i, j, k, l);

				printf("[0x%8x] [0x%8x] [0x%8x]\n", AAAA, BBBB, CCCC);

				int temp = (AAAA + BBBB + CCCC) % 0x100000000;
				printf("[%x] <--> [%x]", temp, target);
				if (temp > target){
						printf("大于了");
						pointer_ABC = getMAX_ABC(&AAAA, &BBBB, &CCCC);

						if (pointer_ABC == &AAAA){
								




								RIGHT_A = *pointer;
								*pointer = LEFT_A + (RIGHT_A - LEFT_A) / 2;
						}
						if (pointer_ABC == &BBBB){
								printf("MAX -> B , [B] = %8x\n", *pointer);
								RIGHT_B = *pointer;
								*pointer = LEFT_B + (RIGHT_B - LEFT_B) / 2;
						}
						if (pointer_ABC == &CCCC){
								printf("MAX -> C , [C] = %8x\n", *pointer);
								RIGHT_C = *pointer;
								*pointer = LEFT_C + (RIGHT_C - LEFT_C) / 2;
						}






						pointer = getMAX(&a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k, &l);
						if (pointer == &a){
								printf("MAX -> A , [A] = %2x\n", *pointer);
								RIGHT_A = *pointer;
								*pointer = LEFT_A + (RIGHT_A - LEFT_A) / 2;
						}
						if (pointer == &b){
								printf("MAX -> B , [B] = %2x\n", *pointer);
								RIGHT_B = *pointer;
								*pointer = LEFT_B + (RIGHT_B - LEFT_B) / 2;
						}
						if (pointer == &c){
								printf("MAX -> C , [C] = %2x\n", *pointer);
								RIGHT_C = *pointer;
								*pointer = LEFT_C + (RIGHT_C - LEFT_C) / 2;
						}
						if (pointer == &d){
								printf("MAX -> D , [D] = %2x\n", *pointer);
								RIGHT_D = *pointer;
								*pointer = LEFT_D + (RIGHT_D - LEFT_D) / 2;
						}
						if (pointer == &e){
								printf("MAX -> E , [E] = %2x\n", *pointer);
								RIGHT_E = *pointer;
								*pointer = LEFT_E + (RIGHT_E - LEFT_E) / 2;
						}
						if (pointer == &f){
								printf("MAX -> F , [F] = %2x\n", *pointer);
								RIGHT_F = *pointer;
								*pointer = LEFT_F + (RIGHT_F - LEFT_F) / 2;
						}
						if (pointer == &g){
								printf("MAX -> G , [G] = %2x\n", *pointer);
								RIGHT_G = *pointer;
								*pointer = LEFT_G + (RIGHT_G - LEFT_G) / 2;
						}
						if (pointer == &h){
								printf("MAX -> H , [H] = %2x\n", *pointer);
								RIGHT_H = *pointer;
								*pointer = LEFT_H + (RIGHT_H - LEFT_H) / 2;
						}
						if (pointer == &i){
								printf("MAX -> I , [I] = %2x\n", *pointer);
								RIGHT_I = *pointer;
								*pointer = LEFT_I + (RIGHT_I - LEFT_I) / 2;
						}
						if (pointer == &j){
								printf("MAX -> J , [J] = %2x\n", *pointer);
								RIGHT_J = *pointer;
								*pointer = LEFT_J + (RIGHT_J - LEFT_J) / 2;
						}
						if (pointer == &k){
								printf("MAX -> K , [K] = %2x\n", *pointer);
								RIGHT_K = *pointer;
								*pointer = LEFT_K + (RIGHT_K - LEFT_K) / 2;
						}
						if (pointer == &l){
								printf("MAX -> L , [L] = %2x\n", *pointer);
								RIGHT_L = *pointer;
								*pointer = LEFT_L + (RIGHT_L - LEFT_L) / 2;
						}

				}else if(temp < target){
						printf("小于了");
						pointer = getMIN(&a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k, &l);
						if (pointer == &a){
								printf("MIN -> A , [A] = %2x\n", *pointer);
								LEFT_A = *pointer;
								*pointer = LEFT_A + (RIGHT_A - LEFT_A) / 2;
						}
						if (pointer == &b){
								printf("MIN -> B , [B] = %2x\n", *pointer);
								LEFT_B = *pointer;
								*pointer = LEFT_B + (RIGHT_B - LEFT_B) / 2;
						}
						if (pointer == &c){
								printf("MIN -> C , [C] = %2x\n", *pointer);
								LEFT_C = *pointer;
								*pointer = LEFT_C + (RIGHT_C - LEFT_C) / 2;
						}
						if (pointer == &d){
								printf("MIN -> D , [D] = %2x\n", *pointer);
								LEFT_D = *pointer;
								*pointer = LEFT_D + (RIGHT_D - LEFT_D) / 2;
						}
						if (pointer == &e){
								printf("MIN -> E , [E] = %2x\n", *pointer);
								LEFT_E = *pointer;
								*pointer = LEFT_E + (RIGHT_E - LEFT_E) / 2;
						}
						if (pointer == &f){
								printf("MIN -> F , [F] = %2x\n", *pointer);
								LEFT_F = *pointer;
								*pointer = LEFT_F + (RIGHT_F - LEFT_F) / 2;
						}
						if (pointer == &g){
								printf("MIN -> G , [G] = %2x\n", *pointer);
								LEFT_G = *pointer;
								*pointer = LEFT_G + (RIGHT_G - LEFT_G) / 2;
						}
						if (pointer == &h){
								printf("MIN -> H , [H] = %2x\n", *pointer);
								LEFT_H = *pointer;
								*pointer = LEFT_H + (RIGHT_H - LEFT_H) / 2;
						}
						if (pointer == &i){
								printf("MIN -> I , [I] = %2x\n", *pointer);
								LEFT_I = *pointer;
								*pointer = LEFT_I + (RIGHT_I - LEFT_I) / 2;
						}
						if (pointer == &j){
								printf("MIN -> J , [J] = %2x\n", *pointer);
								LEFT_J = *pointer;
								*pointer = LEFT_J + (RIGHT_J - LEFT_J) / 2;
						}
						if (pointer == &k){
								printf("MIN -> K , [K] = %2x\n", *pointer);
								LEFT_K = *pointer;
								*pointer = LEFT_K + (RIGHT_K - LEFT_K) / 2;
						}
						if (pointer == &l){
								printf("MIN -> L , [L] = %2x\n", *pointer);
								LEFT_L = *pointer;
								*pointer = LEFT_L + (RIGHT_L - LEFT_L) / 2;
						}

				}else{
						printf("[FOUND] : [0x%8x] [0x%8x] [0x%8x]\n", AAAA, BBBB, CCCC);
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
