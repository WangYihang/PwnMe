#!/usr/bin/env python
# coding:utf-8

from pwn import *



print "单字节指令 : "
for i in range(32,128):
    result = "[%c] -> %s" % (chr(i), disasm(chr(i)))
    print result
    with open("single.dat", "a+") as single:
        single.write(result+"\n")
    


print "双字节指令 : "
for i in range(32,128):
    for j in range(32,128):
        result = "[%c%c] -> %s" % (chr(i), chr(j), disasm(chr(i) + chr(j)))
        print result
        with open("double.dat", "a+") as double:
            double.write(result+"\n")
