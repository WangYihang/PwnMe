#!/usr/bin/env python
# coding:utf-8

import sys

start = ord("0")

def getJunk(length):
    global start
    result = ""
    size = (length / 4)
    padding = length - size * 4
    for i in range(size):
        result += chr(start + i) * 2 + "\x00\x00"
    return result + "@@\x00\x00"[0:padding]


def main():
    if len(sys.argv) != 2:
        print "Usage : "
        print "        python getJunk.py [LENGTH]"
        exit(1)
    junk = getJunk(int(sys.argv[1]))
    print junk
    with open("junk.dat","w") as f:
        f.write(junk)


if __name__ == "__main__":
    main()
