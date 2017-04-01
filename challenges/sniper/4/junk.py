#!/usr/bin/env python
# encoding:utf-8

import sys

def getJunk(length):
    junk = ""
    temp = length / 4
    for i in range(temp):
        junk += "%04d" % ((i+1) * 4)
    return junk

def find(length):
    return getJunk(length) + "@" * 4

def main():
    if len(sys.argv) != 2:
        print "Usage : "
        print "        python %s [LENGTH]" % (sys.argv[0])
        exit(1)
    length = int(sys.argv[1])
    print find(length)

if __name__ == "__main__":
    main()
