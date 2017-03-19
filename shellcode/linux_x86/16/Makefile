shellcode:shellcode.o
	ld -o shellcode shellcode.o
shellcode.o:shellcode.asm
	nasm -f elf shellcode.asm
clean:
	rm ./shellcode.o
	rm ./shellcode
