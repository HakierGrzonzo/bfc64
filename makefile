bfc64: main.o parser.o symbol.o template.o compiler.o
	g++ main.o parser.o symbol.o template.o compiler.o -o bfc64

parser.o: processor/parser.cpp
	g++ -c processor/parser.cpp

compiler.o: processor/compiler.cpp
	g++ -c processor/compiler.cpp

symbol.o: processor/symbols/symbol.cpp
	g++ -c processor/symbols/symbol.cpp

main.o: main.cpp
	g++ -c main.cpp

template.o: processor/arch/template.cpp
	g++ -c processor/arch/template.cpp

processor/arch/template.cpp: processor/arch/templateGen.py processor/arch/c64/* processor/arch/template.cpp.template
	python processor/arch/templateGen.py processor/arch/c64/

test.asm: bfc64 tests/test.b
	./bfc64 tests/test.b > test.asm

test.prg: test.asm
	kickass -showmem test.asm

test: test.prg
	x64sc -autostart $(PWD)/test.prg

clean:
	rm *.o bfc64 processor/arch/template.cpp test.asm test.prg