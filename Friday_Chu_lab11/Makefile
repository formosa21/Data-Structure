
lab10: main.o Node_k.o Set.o Min_Span_Tree.o Hash_Table.o Node.o
	g++ -g -std=c++11 Min_Span_Tree.o Set.o Hash_Table.o Node_k.o Node.o main.o -o lab10

main.o: main.cpp Min_Span_Tree.h Min_Span_Tree.cpp Set.h Node_k.h
	g++ -c -g -std=c++11 main.cpp

Min_Span_Tree.o: Min_Span_Tree.h Min_Span_Tree.cpp Set.h Node_k.h ./Min5Heap/Heap.h ./Min5Heap/Heap.hpp  ./BinarySearchTree/BinarySearchTree.h
	g++ -c -g -std=c++11 Min_Span_Tree.cpp

Node_k.o: Node_k.h Node_k.cpp
	g++ -c -g -std=c++11 Node_k.cpp

Set.o: Set.h Set.cpp Node_k.h Node_k.cpp
	g++ -c -g -std=c++11 Set.cpp

clean:
	rm *.o lab10
