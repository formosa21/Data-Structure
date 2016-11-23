lab7: main.o Heap.o MinMaxHeap.o 
	g++ -g -Wall -std=c++11 main.o Heap.o MinMaxHeap.o -o lab7

main.o: main.cpp ./min5Heap/Heap.h ./MinMaxHeap/MinMaxHeap.h 
	g++ -c -g -std=c++11 main.cpp

Heap.o: ./min5Heap/Heap.h ./min5Heap/Heap.cpp
	g++ -c -g -std=c++11 ./min5Heap/Heap.h ./min5Heap/Heap.cpp

MinMaxHeap.o: ./MinMaxHeap/MinMaxHeap.h ./MinMaxHeap/MinMaxHeap.cpp
	g++ -c -g -std=c++11 ./MinMaxHeap/MinMaxHeap.h ./MinMaxHeap/MinMaxHeap.cpp

clean:
	rm *.o lab7
