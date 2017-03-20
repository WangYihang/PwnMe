#!/usr/bin/env python

for i in range(32, 128):
    for j in range(32, 128):
        if (i & j) == 0:
            print "[%c] & [%c] = 0 (%s, %s)" % (chr(i), chr(j), hex(i), hex(j))
