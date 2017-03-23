global _start
	_start:
		; ssize_t read(int fd, void *buf, size_t count);
		xor eax, eax
		cdq
		mov dl, 10H ; count = 16
		push ddd ; buf = .data
		pop eax
		xor ebx, ebx ; fd = 0
		mov al, 03H
		int 80H
	ddd:
		db 0,0,0,0,0,0,0
