ref/vuln: vuln.c
	gcc -fno-stack-protector vuln.c -o ref/vuln

ref/write: ref/write.c
	gcc ref/write.c -o ref/write

_PHONY: clean
clean:
	rm -f ref/vuln
