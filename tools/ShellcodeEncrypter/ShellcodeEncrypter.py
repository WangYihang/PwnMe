#!/usr/bin/env python
# coding:utf-8

import sys
import binascii

def encrypt(shellcode, password):
    result = ""
    for i in shellcode:
        result += chr(ord(i) ^ password)
    return result

def build(shellcode, password):
    length = len(shellcode)
    result = "\xeb\x10\x5e\x31\xc9\xb1" + (chr(length)) + "\x8a\x06\x34" + chr(password) + "\x88\x06\x46\xe2\xf7\xeb\x05\xe8\xeb\xff\xff\xff"
    result += shellcode
    return result

def main():
    if len(sys.argv) != 3:
        print "Usage : "
        print "        python ShellcodeEncrypt.py [SHELLCODE_FILE] [PASSWORD]"
        print "TIPS : "
        print "        1. password must bigger than 0 and less than 255"
        print "CONTACT : "
        print "        If  you have any questions, please contact me : [wangyihanger@gmail.com]"
        exit(1)
    try:
        filename = sys.argv[1]
        shellcode_file  = open(filename)
        shellcode = shellcode_file.read()
        if len(shellcode) > 0xFF:
            print "[ERROR] : The shellcode is too long."
            exit(3)
    except:
        print "Open [SHELLCODE_FILE] failed."
        exit(2)
    password = int(sys.argv[2], 10) % 255
    print "[SHELLCODE] : " + binascii.b2a_hex(shellcode)
    print "[PASSWORD] : " + str(password)
    encrypted_shellcode = encrypt(shellcode, password)
    result = build(encrypted_shellcode, password)
    print "[ENCRYPTED] : " + binascii.b2a_hex(result)
    result_file = open("encrypted_" + filename, "w")
    result_file.write(result)
    result_file.close()
    print "[%s] Saved!" % (filename)

if __name__ == "__main__":
    main()
