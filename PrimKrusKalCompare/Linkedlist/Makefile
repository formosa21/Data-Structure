program: main.o 
	g++ -g -Wall -std=c++11 main.o -o program

main.o: main.cpp node.h linkedlist.h
	g++ -g -Wall -std=c++11 -c main.cpp

clean:
	rm *.o program	
