#include "linkedlist.h"
#include "node.h"
#include <fstream>

void printMenu();

int main(){
	std::ifstream myfile;
	std::ifstream myfile2;
	myfile.open("data.txt");
	myfile2.open("data2.txt");
	linkedlist<int> mylist; // linkedlist used to store numbers in data1.txt
	linkedlist<int> mylist2; // linkedlist used to store numbers in data2.txt	
	int num;
	while(myfile >> num){
		mylist.insert(num);
	}
	myfile.close();
	while(myfile2 >> num){
		mylist2.insert(num);
	}
	myfile2.close();

	int choice;
	do{
		std::cout << "\n..........................................................\n";
		printMenu();
		std::cin >> choice;
		
		switch(choice){
			case 1:	
				int number;
				std::cout << "Choose a number to be inserted to the list: \n> ";
				std::cin >> number;
				mylist.insert(number);
				break;
			case 2:
				int number2;
				std::cout << "Choose a number to be deleted from the list: \n> ";
				std::cin >> number2;
				mylist.erase(number2);
				break;
			case 3:
				mylist.reverse();
				break;
			case 4:
				mylist.concatenate(mylist.getfirst(), mylist2.getfirst());
				break;
			case 5:
				mylist.print();
				break;
			case 6:
				std::cout << "\nBye";
				break;
		}

	}while(choice != 6);

	return 0;
}

void printMenu(){
	std::cout << "Please choose one of the following commands:\n";
	std::cout << "1- insert\n";
	std::cout << "2- delete\n";
	std::cout << "3- reverse\n";
	std::cout << "4- concatenate\n";
	std::cout << "5- print\n";
	std::cout << "6- exit\n";
	std::cout << "> ";
}
