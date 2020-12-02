bfc64: main.o
	g++ main.o -o bfc64

main.o: main.cpp
	g++ -c main.cpp

test: bfc64
	./bfc64 tests/test.bf 

clean:
	rm *.o