lab5: main.o Heap.o
	g++ -g -Wall -std=c++11 main.o Heap.o -o lab5

main.o: main.cpp Heap.h 
	g++ -g -Wall -std=c++11 -c main.cpp

Heap.o: Heap.h Heap.cpp
	g++ -g -Wall -std=c++11 -c Heap.cpp

clean:
	rm *.o lab5
