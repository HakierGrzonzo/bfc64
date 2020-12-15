bfc64: main.o parser.o symbol.o template.o
	g++ main.o parser.o symbol.o template.o -o bfc64

parser.o: processor/parser.cpp
	g++ -c processor/parser.cpp

symbol.o: processor/symbols/symbol.cpp
	g++ -c processor/symbols/symbol.cpp

main.o: main.cpp
	g++ -c main.cpp

template.o: processor/arch/template.cpp
	g++ -c processor/arch/template.cpp

processor/arch/template.cpp: processor/arch/templateGen.py processor/arch/c64/*
	python processor/arch/templateGen.py processor/arch/c64/

test: bfc64
	./bfc64 tests/test.b 

clean:
	rm *.o bfc64 processor/arch/template.cpp