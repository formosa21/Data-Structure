#ifndef NODE_H
#define NODE_H
class Node{

	private:
		bool flag;
		int value;
	public:
		Node();
		Node(int);
		int getValue() const;
		bool getFlag() const;
		void setValue(int value);
		void setFlag();
		char* printFlag() const;
};
#include "Node.hpp"
#endif
