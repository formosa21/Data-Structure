#include "Heap.h"
#include <fstream>
#include <iostream>

void printMenu();
struct edge{
		int cost;
		int x;
		int y;
		bool operator > (const edge& a){
			return (cost > a.cost ? true : false);
		}
		bool operator < (const edge& a){
			return (cost < a.cost ? true : false);
		}
		bool operator == (const edge& a){
			return (cost == a.cost ? true : false);
		}
		bool operator <= (const edge& a){
			return (cost <= a.cost ? true : false);
		}
		bool operator >= (const edge& a){
			return (cost >= a.cost ? true : false);
		}
		void operator = (const edge& a){
			cost = a.cost;
			x = a.x;
			y = a.y;
		}
		friend std::ostream& operator << (std::ostream& os, const edge& a){
			os << a.cost;
			return os;
		}

	};

int main(int argc, char* argv[]){

	edge *e1 = new edge(); e1->cost = 3; e1->x = 1; e1->y = 3;
	edge *e2 = new edge(); e2->cost = 5; e2->x = 2; e2->y = 4;
	edge *e3 = new edge(); e3->cost = 1; e3->x = 5; e3->y = 6;

	Heap<edge> *pq = new Heap<edge>();
	pq->insert(e1);
	pq->insert(e2);
	pq->insert(e3);
	pq->print();

	pq->pop();
	pq->print();

	/*
	std::ifstream myfile;
	myfile.open("data.txt");

	Heap myheap;
	int num;

	while(myfile >> num){
		myheap.constructive_insert(num);
	}
	myheap.heapify_up(); // heapify: bottom-up approach

	int choice;
	int user_number;
	do{
		printMenu();
		std::cin >> choice;
		switch(choice){
			case 1:
				std::cout << "Please insert the number that you want to be inserted in the heap\n"
					<< ">";
				std::cin >> user_number;
				myheap.insert(user_number);
				break;

			case 2:
				myheap.deleteMin();
				break;

			case 3:
				myheap.deleteMax();
				break;

			case 4:
				std::cout << "Please insert the number that you want to remove from the 5-Heap\n"
					<< ">";
				std::cin >> user_number;
				myheap.remove(user_number);
				break;

			case 5:
				myheap.print();
				break;
			case 6:
				break;
			default:
				std::cout << "Please enter something valid\n";
				break;
		}
	}while(choice != 6);



	*/
	return 0;
}

void printMenu(){
	std::cout << "\n..........................................................\n";
	std::cout << "Please choose one of the following commands:\n"
		<< "1- insert\n"
		<< "2- deletemin\n"
		<< "3- deletemax\n"
		<< "4- remove\n"
		<< "5- levelorder\n"
		<< "6- exit\n"
		<< ">";
}
