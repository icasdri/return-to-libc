all: ref/vuln ref/write

ref/vuln: vuln.c
	gcc -fno-stack-protector vuln.c -o ref/vuln

ref/write: ref/write.c
	gcc ref/write.c -o ref/write

clean:
	rm -f ref/vuln
	rm -f ref/write

_PHONY: all clean
