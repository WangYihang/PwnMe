for i in `seq 0 4096`;do { ./bashloop $i | grep -v 'Nope. Pick another number between 0 and 4096'; }; done
