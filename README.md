# bfc64

A working brainfuck (non-wrapping, 8 bit, optimizing) cross-compiler for commodore 64. Compiles brainfuck to Kickassembler code.

## compilaton

To compile run:
```bash
make
```

To automaticly build included program, assemble it in kickassembler and run it with VICE run:

```bash
make test
```

Run `sudo make install` if you want to install it.

## Dependancies:

Compile time: 
- gcc
- make
- python - to build `template.cpp`

You need to have kickassembler installed as the compiler outputs assembly code for it.
