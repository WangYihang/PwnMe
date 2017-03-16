#!/usr/bin/env python
# coding:utf-8

import sys
from pwn import disasm

def getWhiteList():
    whiteList = []
    for i in range(32, 128):
        whiteList.append(chr(i))
    return whiteList

def getSameCommand(command):
    result = ""
    result = command # TODO 给用户修改意见
    return result

def check(shellcode):
    whiteList = getWhiteList()
    for i in shellcode:
        if i not in whiteList: 
            print "-" * 16
            print "[0x%x] : " % ord(i),"\t",
            print disasm(i) # TODO 这样可能会分开不同的指令
            print "[SUGGEST] : ",
            print "0x%x" % ord(getSameCommand(i))

def main():
    if len(sys.argv) != 2:
        print "Usage : "
        print "        python CheckNotASCII.py [SHELLCODE_NAME]"
        exit(1)
    filename = sys.argv[1]
    try:
        shellcode_file = open(filename, "r")
        shellcode = shellcode_file.read()
    except:
        print "Open file [%s] error!" % (filename)
        exit(2)
    check(shellcode)

if __name__ == "__main__":
    main()
