
test: main.o first.o second.o
	g++ -o test main.o first.o second.o

main.o: main.cpp
	g++ -c main.cpp

first.o: first.cpp
	g++ -c first.cpp

second.o: second.cpp
	g++ -c second.cpp

clean:
	rm -f *.o test
