#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "Bnode.h"
#include "Queue.h"
#include <iostream>

enum Order{
	PRE_ORDER,
	IN_ORDER,
	POST_ORDER
};


template<typename T>
class BinarySearchTree{
	private:
		bool add(T value, Bnode<T>* subtree);
		void deleteTree(Bnode<T>* subtree); //figure this out
		Bnode<T>* search(T value, Bnode<T>* subtree) const;
		void printTree(Bnode<T>* subtree, Order order) const;
		void deleteMin(Bnode<T>*& subtree);
		void deleteMax(Bnode<T>*& subtree);
		void remove(const T value, Bnode<T>*& subtree);

		Bnode<T>* m_root;

	public:
		BinarySearchTree();
		BinarySearchTree(const BinarySearchTree<T>& other);
		~BinarySearchTree();
		bool isEmpty() const;
		bool insert(T value);
		void printTree(Order order) const;
		Bnode<T>* search(T value);
		void deleteMin();
		void deleteMax();
		void remove(const T value);
		void levelOrderTraverse() const;
		Bnode<T>* getLeftMost(Bnode<T>* subtree) const; // node with smallest value
		Bnode<T>* getRightMost(Bnode<T>* subtree) const; // node with largest value
};

#include "BinarySearchTree.hpp"
#endif
