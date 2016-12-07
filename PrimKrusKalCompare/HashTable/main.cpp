#include "Hash_Table.h"
#include <fstream>

void printMenu();

int main(int argc, char* argv[]){
	ifstream mystream;
	mystream.open("data.txt");
	int num;
	mystream >> num;
	Hash_Table hm(num);
	while(mystream >> num){
		hm.insert(num);
	}
	std::cout << "size: " << hm.size() << "\n";
	int option;
	int value;
	do{
		printMenu();
		cin >> option;
		switch(option){
			case 1:
				cout << "Which number do you want to insert into the hash table?\n> ";
				cin >> value;
				hm.insert(value);
				break;
			case 2:
				cout << "Which number do you want to delete in the hash table?\n> ";
				cin >> value;
				hm.remove(value);
				break;
			case 3:
				hm.print();
				break;
			case 4:
				break;
			default:
				cout << "Oops\n";
				break;
		}
	}while(option != 4);



	return 0;
}

void printMenu(){
	cout << "-----------------------------\n";
	cout << "Please choose one of the following commands:\n"
		<<	"1- insert\n"
		<<	"2- delete\n"
		<<	"3- print\n"
		<<	"4- exit\n"
		<<	"> ";
}
