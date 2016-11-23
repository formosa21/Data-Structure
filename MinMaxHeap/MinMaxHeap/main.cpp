#include "MinMaxHeap.h"
#include <fstream>

void printMenu();

int main(){
	std::ifstream myfile;
	myfile.open("data.txt");

	MinMaxHeap my_mmh;
	int num;
	while(myfile >> num)
		my_mmh.constructive_insert(num);
	my_mmh.heapify();

	int choice;
	int user_number;
	do{
		printMenu();
		std::cin >> choice;
		switch(choice){
			case 1:
				std::cout << "Please insert the number that you want to be inserted in the treei\n"
					<< ">";
				std::cin >> user_number;
				my_mmh.insert(user_number);
				break;

			case 2:
				my_mmh.deleteMin();
				break;

			case 3:
				my_mmh.deleteMax();
				break;

			case 4:
				std::cout << "Level order:\n";
				my_mmh.levelOrder();
				break;

			case 5:
				break;
			default:
				std::cout << "Please enter something valid\n";
				break;
		}
	}while(choice != 5);

	return 0;
}

void printMenu(){
	std::cout << "\n...............................................\n";
	std::cout << "Please choose one of the following commands:\n"
		<< "1- insert\n"
		<< "2- deletemin\n"
		<< "3- deletemax\n"
		<< "4- levelorder\n"
		<< "5- exit\n"
		<< ">";
}
