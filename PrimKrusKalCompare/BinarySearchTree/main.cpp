#include "BinarySearchTree.h"
int main(int argc, char* argv[]){
	BinarySearchTree<int> bt;
	bt.add(8);
	bt.add(1);
	bt.add(2);
	bt.add(12);
	bt.add(9);
	bt.add(11);
	bt.add(0);
	bt.printTree(PRE_ORDER);
/*
	if(bt.search(11))
		std::cout << "11 is here!";
	if(!bt.search(333))
		std::cout << "333 not here!";
	bt.deleteMin();
	bt.deleteMin();
	bt.deleteMin();
	bt.deleteMin();
	*/
	std::cout << "2nd time~!----\n";

//	bt.remove(8);
//	bt.remove(9);
	bt.printTree(PRE_ORDER);
	std::cout << " ";

	bt.levelOrderTraverse();
	if(bt.find(121))
		std::cout << "\n found!"  << "\n";
		else
				std::cout << "\n NOT found!"  << "\n";

	std::cout << bt.size();
/*

	Queue<BinarySearchTree<int>*> qbst;
	qbst.enqueue(&bt);
	qbst.dequeue();
*/
	/*QueueBox<int>* qb = new QueueBox<int>(9);
	Queue<QueueBox<int>*>* the_queue = new Queue<QueueBox<int>*>();
	the_queue->enqueue(qb);
	*/

}
