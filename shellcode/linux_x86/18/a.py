def cmp(target, a, b):
    if (a + b) > target:
            return 1
    elif (a + b) < target:
            return -1
    else:
            return 0

def number(shellcode):
    right = 0x7f7f7f7f
    left = 0x20202020
    size = right - left
    a = left + size / 2
    b = a
    MAX_STEP = 40
    step = 0
    while True:
        step += 1
        temp = cmp(shellcode, a, b)
        print "[cmp] = %d, [a] = %s, [b] = %s" % (temp, hex(a), hex(b)) 
        if temp == 1:
            right = a
            a = (right - left) / 2
        if temp == -1:
            left = a
            a = (right - left) / 2
        if temp == 0:
            return (a, b)
        if step > MAX_STEP:
            return "False"


shellcode = 0x5899cd80
print number(2**32 - shellcode)
