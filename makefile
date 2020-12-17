bfc64: main.o parser.o symbol.o template.o compiler.o optimizer.o
	g++ main.o parser.o symbol.o template.o compiler.o optimizer.o -o bfc64

parser.o: processor/parser.cpp
	g++ -c processor/parser.cpp

compiler.o: processor/compiler.cpp
	g++ -c processor/compiler.cpp

optimizer.o: processor/optimizer.cpp
	g++ -c processor/optimizer.cpp

symbol.o: processor/symbols/symbol.cpp
	g++ -c processor/symbols/symbol.cpp

main.o: main.cpp
	g++ -c main.cpp

template.o: processor/arch/template.cpp
	g++ -c processor/arch/template.cpp

processor/arch/template.cpp: processor/arch/templateGen.py processor/arch/c64/* processor/arch/template.cpp.template
	python processor/arch/templateGen.py processor/arch/c64/

a.asm: bfc64 tests/test.b
	./bfc64 tests/test.b

a.prg: a.asm
	kickass -showmem a.asm

test: a.prg
	x64sc -autostart $(PWD)/a.prg

docs: docs/main.tex
	xelatex docs/main.tex

clean:
	rm *.o bfc64 processor/arch/template.cpp a.asm a.prg 
