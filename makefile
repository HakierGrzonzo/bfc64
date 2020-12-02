bfc64: main.o parser.o symbol.o
	g++ main.o parser.o symbol.o -o bfc64

parser.o: processor/parser.cpp
	g++ -c processor/parser.cpp

symbol.o: processor/symbols/symbol.cpp
	g++ -c processor/symbols/symbol.cpp

main.o: main.cpp
	g++ -c main.cpp

test: bfc64
	./bfc64 tests/test.b 

clean:
	rm *.o