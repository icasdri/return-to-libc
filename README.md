# return-to-libc
A simple example program vulnerable to a [return-to-libc](https://en.wikipedia.org/wiki/Return-to-libc) attack via a stack [buffer overflow](https://en.wikipedia.org/wiki/Buffer_overflow) which overwrites a function return address.

We workaround (via compiler flags and wrappers) [ASLR](https://en.wikipedia.org/wiki/ASLR) and [stack protectors](https://en.wikipedia.org/wiki/Stack-Smashing_Protector), modern exploit mitigation mechanisms that would prevent this specific example from working (aka. being exploited).

## Usage
(if you can call it that)

```
make

# run the program normally (inputs shorter than 10 are fine)
./vuln

# generate attack input
./ref/write > evil.txt

# exploit!
./vuln < evil.txt
```

## Organization

* `Makefile` makes `ref/vuln` with `-fno-stack-protector` and makes `ref/write` normally.
* `vuln` is a wrapper script that runs `ref/vuln` with ASLR disabled via `setarch ... -R`
* `vuln.c` contains the source code for the vulnerable program.
    * For inputs shorter than 10 characters in length, the program is well-behaved and will print the length of the input it received.
* `write.c` contains code that can be used to generate an attack input.
    * When passed to `vuln`, the generated input should result in "PWNED!!!!" being printed.
    * This assumes the C library function `puts` will be loaded at address `0x7fffffffffff` when `vuln` is run. This address should be changed to the real address which can be found by running `ref/vuln` in a debugger (e.g. in *gdb*, `break puts`).
