lab8: main.o Leftist_Heap.o
	g++ -g -Wall -std=c++11 main.o Leftist_Heap.o -o lab8

main.o: main.cpp Leftist_Heap.o 
	g++ -g -Wall -std=c++11 -c main.cpp

Leftist_Heap.o: Leftist_Heap.h Leftist_Heap.cpp 
	g++ -g -Wall -std=c++11 -c Leftist_Heap.cpp

clean:
	rm *.o lab8
