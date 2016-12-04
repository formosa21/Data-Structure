#include "Node.h"
#include <iostream>
using namespace std;

Node::Node(){
	flag = false;
	value = -1;
}

Node::Node(int x){
	flag = false;
	value = x;
}

int Node::getValue() const{
	return value;
}

bool Node::getFlag() const{
	return flag;
}

void Node::setValue(int x){
	value = x;
}

void Node::setFlag(){
	flag = true;
}

char* Node::printFlag() const{
	if(flag)
		return "true";
	else
		return "false";
}
