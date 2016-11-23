lab8: main.o Skew_Heap.o
	g++ -g -Wall -std=c++11 main.o Skew_Heap.o -o lab8

main.o: main.cpp Skew_Heap.o 
	g++ -g -Wall -std=c++11 -c main.cpp

Skew_Heap.o: Skew_Heap.h Skew_Heap.cpp 
	g++ -g -Wall -std=c++11 -c Skew_Heap.cpp

clean:
	rm *.o lab8
