all:bingo_86 bingo_64
bingo_86:bingo.c
	gcc -o bingo_86 -m32 -fno-stack-protector -z execstack bingo.c
bingo_64:bingo.c
	gcc -o bingo_64 -m64 -fno-stack-protector -z execstack bingo.c
clean:
	rm ./bingo_86
	rm ./bingo_64
