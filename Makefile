
test: main.o first.o
	g++ -o test main.o first.o

main.o: main.cpp
	g++ -c main.cpp

first.o: first.cpp
	g++ -c first.cpp

clean:
	rm -f *.o first
