#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"
#include <iostream> 

template <typename T>
class linkedlist{
	node<T>* m_first;	
	int m_size;

	public:
		linkedlist();
		~linkedlist();
		int size() const;
		bool isEmpty() const;
		void print() const;
		void insert(const T&); // insert to the back of the list
		void erase(const T&);
		bool find(const T&) const;
		void reverse();
		void removeFront();
		void concatenate(node<T>* thislist_ptr, node<T>* otherlist_start_ptr);
		node<T>* getfirst() const;
};

#include "linkedlist.hpp"
#endif
