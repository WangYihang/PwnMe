all:bingo_86 bingo_64
bingo_64:bingo.c
	gcc -g -m64 -fno-stack-protector -z execstack -o bingo_64 bingo.c
bingo_86:bingo.c
	gcc -g -m32 -fno-stack-protector -z execstack -o bingo_32 bingo.c
clean:
	rm ./bingo
