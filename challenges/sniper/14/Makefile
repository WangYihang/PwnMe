all:vulnerable bruter
vulnerable:vulnerable.c
	gcc -o vulnerable -fno-stack-protector -z execstack vulnerable.c
bruter:bruter.c
	gcc -o bruter bruter.c
clean:
	rm ./vulnerable
	rm ./bruter
