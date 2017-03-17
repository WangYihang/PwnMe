#!/usr/bin/env python
# coding:utf-8

from string import maketrans

SIZE = 0x10

def trans(text, intab, outtab):
    length = len(intab)
    for i in range(length):
        text = text.replace(intab[i], outtab[i])
    return text

def getInTable():
    '''
    临时密文可行域
    '''
    global SIZE
    inTable = []
    for i in range(SIZE):
        inTable.append(chr(i))
    return inTable

def getOutTable():
    '''
    密文可行域
    '''
    global SIZE
    outTable = []
    inTable = getInTable()
    for i in inTable:
        outTable.append(chr(ord(i) + ord("A")))
    return outTable

def replace(cipher, FLAG):
    '''
    将临时密文的所有字节映射到密文可行域
    '''
    intab = getInTable()
    outtab = getOutTable()
    if len(intab) != len(outtab):
        print "转换表长度不同"
        exit(2)
    if FLAG == "e":
        return trans(cipher, intab, outtab)
    elif FLAG == "d":
        return trans(cipher, outtab, intab)
    else:
        return cipher

def encrypt(plain):
    global SIZE
    cipher = ""
    for i in plain:
        # 0xAB
        cipher += chr((ord(i) / SIZE)) # A
        cipher += chr((ord(i) % SIZE)) # B
    cipher = replace(cipher, "e")
    return cipher

def decrypt(cipher):
    cipher = replace(cipher, "d")
    plain = ""
    for i in range(0, len(cipher), 2):
        plain += chr((ord(cipher[i])) * SIZE + (ord(cipher[i+1])))
    return plain

def printAssembly(cipher):
    for i in cipher:
        print "\tdb 0" + hex(ord(i))[2:] + "H"

def main():
    # plain = "\x31\xc9\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x6a\x0b\x58\x99\xcd\x80"
    plain = "A"
    print "[PLAIN] : " + plain + "\t[Bytes : " + str(len(plain)) + "]"
    cipher = encrypt(plain)
    print "[CIPHER] : " + cipher + "\t[Bytes : " + str(len(cipher)) + "]"
    decrypted = decrypt(cipher)
    print "[DECRYPTED] : " + decrypted + "\t[Bytes : " + str(len(decrypted)) + "]"
    print "=" * 16
    printAssembly(cipher)

if __name__ == "__main__":
    main()
