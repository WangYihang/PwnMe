#!/usr/bin/python -u
# encoding: utf-8

import random, string, subprocess, os, sys
from hashlib import sha256

os.chdir(os.path.dirname(os.path.realpath(__file__)))

def exec_serv(name, payload):
    p = subprocess.Popen(name, stdin=subprocess.PIPE, stdout=file('/dev/null','w'), stderr=subprocess.STDOUT)
    p.stdin.write(payload)
    p.wait()

if __name__ == '__main__':
    payload = sys.stdin.read(0x100)
    exec_serv(['./ld-linux.so.2', '--library-path', '.', './level12'], payload)
