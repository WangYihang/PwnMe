shellcode:shellcode.o
	ld -o shellcode shellcode.o
shellcode.o:shellcode.asm
	nasm -f elf shellcode.asm
encrypt:encrypt.c
	gcc -o encrypt encrypt.c
clean:
	rm ./shellcode.o
	rm ./shellcode
	rm ./encrypt
