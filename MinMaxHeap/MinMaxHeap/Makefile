lab7: main.o MinMaxHeap.o
	g++ -g -Wall -std=c++11 main.o MinMaxHeap.o -o lab7

main.o: main.cpp MinMaxHeap.h
	g++ -g -Wall -std=c++11 -c main.cpp

MinMaxHeap.o: MinMaxHeap.h MinMaxHeap.cpp
	g++ -g -Wall -std=c++11 -c MinMaxHeap.cpp

clean:
	rm *.o lab7
