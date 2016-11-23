#ifndef Skew_HEAP_H
#define Skew_HEAP_H

#include "Node.h"
#include "Queue.h"
#include <iostream>
#include "../Order.h"


class Skew_Heap{
	private:
		Node *m_root;
		void Print_Tree(Node*, Order) const;
	public:
		Skew_Heap();
		~Skew_Heap();
		void deleteTree(Node *subtree);
		void insert(int value);
		void deleteMin();
		Node* concate(Node *n1, Node *n2);
		void Print_Tree(Order) const;
};

Skew_Heap::Skew_Heap(){
	m_root = nullptr;
}

Skew_Heap::~Skew_Heap(){
	if(m_root != nullptr){
		deleteTree(m_root);
		m_root = nullptr;
	}
}

void Skew_Heap::deleteTree(Node *subtree){
	if(subtree->getLeft() != nullptr){
		deleteTree(subtree->getLeft());
		subtree->setLeft(nullptr);
	}
	if(subtree->getRight() != nullptr){
		deleteTree(subtree->getRight());
		subtree->setRight(nullptr);
	}

	delete subtree;
}

void Skew_Heap::insert(int value){
	Node *node = new Node(value);
	m_root = concate(m_root, node);
	node = nullptr;
}

void Skew_Heap::deleteMin(){
	Node *r = m_root->getRight();
	Node *l = m_root->getLeft();
	delete m_root;
	m_root = concate(r, l);
}

Node* Skew_Heap::concate(Node *n1, Node *n2){
	if(n1 == nullptr)
		return n2;
	else if(n2 == nullptr)
		return n1;
	else if(n1->getValue() > n2->getValue()){
		Node *temp = n1;
		n1 = n2;
		n2 = temp;
	}
	Node *temp = n1->getRight();
	n1->setRight(n1->getLeft());
	n1->setLeft(concate(temp, n2));
	return n1;
}

void Skew_Heap::Print_Tree(Order order) const{
	Print_Tree(m_root, order);
}

void Skew_Heap::Print_Tree(Node* subtree, Order order) const{
	if(subtree == nullptr)
		return;

	switch(order){
		case PRE_ORDER:
			std::cout << subtree->getValue() << " ";
			Print_Tree(subtree->getLeft(), order);
			Print_Tree(subtree->getRight(), order);
			break;
		case IN_ORDER:
			Print_Tree(subtree->getLeft(), order);
			std::cout << subtree->getValue() << " ";
			Print_Tree(subtree->getRight(), order);
			break;
		case LEVEL_ORDER:
			if(m_root != nullptr){
				Node *node_ptr;
				Queue<Node*> *q = new Queue<Node*>();
				q->enqueue(m_root);
				do{
					node_ptr = q->peek();
					std::cout << node_ptr->getValue() << " ";
					if(node_ptr->getLeft() != nullptr)
						q->enqueue(node_ptr->getLeft());
					if(node_ptr->getRight() != nullptr)
						q->enqueue(node_ptr->getRight());
					q->dequeue();
				}while(!q->isEmpty());
				delete q; q = nullptr;

			}
			break;
		default:
			break;
	}
}

#endif
