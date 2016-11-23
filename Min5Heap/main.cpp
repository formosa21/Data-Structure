#include "Heap.h"
#include <fstream>

void printMenu();

int main(int argc, char* argv[]){
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
