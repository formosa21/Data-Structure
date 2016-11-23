#include <fstream>
#include "Leftist_Heap.h"

void printMenu();

int main(int argc, char* argv[]){
	Leftist_Heap *lh = new Leftist_Heap();
	std::ifstream myfile;
	myfile.open("data.txt");
	int num;
	while(myfile >> num)
		lh->insert(num);

	int choice;
	int user_number;
	do{
		std::cout << "\n..........................................................\n";

		printMenu();
		std::cin >> choice;
		switch(choice){
			case 1: std::cout << "Please enter a number to insert in to the data structure:\n";
				std::cin >> user_number;
				lh->insert(user_number);
				break;
			case 2:
				lh->deleteMin();
				break;
			case 3:
				std::cout << "Pre order: \n";
				lh->Print_Tree(PRE_ORDER);
				break;
			case 4:
				std::cout << "In order: \n";
				lh->Print_Tree(IN_ORDER);
				break;
			case 5:	
				std::cout << "Level order: \n";
				lh->Print_Tree(LEVEL_ORDER);
				break;
			case 6:
				break;
			default:
				break;
		}
	}while(choice != 6);
	delete lh; lh = nullptr;
	return 0;
}

void printMenu(){
	std::cout << "Please choose one the following commands:\n"
	<<"1-insert\n"
	<<"2-deletemin\n"
	<<"3-preorder\n"
	<<"4-inorder\n"
	<<"5-Levelorder\n"
	<<"6-end\n"
	<<"\n> ";
}
