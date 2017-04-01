all:rop_86 rop_64
rop_64:rop.c
	gcc -g -m64 -fno-stack-protector -z execstack -o rop_64 rop.c
rop_86:rop.c
	gcc -g -m32 -fno-stack-protector -z execstack -o rop_86 rop.c
clean:
	rm ./rop_86
	rm ./rop_64
