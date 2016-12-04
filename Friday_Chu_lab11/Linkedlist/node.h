#ifndef NODE_H
#define NODE_H

template <typename T>
class node{
	T m_value;
	node* m_next;
	
	public:
		node();
		node(const T& value);
		int getValue() const;
		void setValue(int value);
		node<T>* getNext() const; 
		void setNext(node* nodeptr);
};

#include "node.hpp"
#endif
