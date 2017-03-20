def getMAX(a, b, c):
    MAX = a
    if (b > MAX):
        MAX = b
    if (c > MAX):
        MAX = c
    return MAX


def do(target, a, b, c):
    RIGHT = 0x7f7f7f7f
    LEFT = 0x20202020
    if (target > ((a + b + c) % 0xFFFFFFFF)):
        


a = 0x20202020
b = a
c = a
