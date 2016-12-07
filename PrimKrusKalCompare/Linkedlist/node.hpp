#include "node.h"
template <typename T>
node<T>::node():m_next(nullptr){
}

template <typename T>
node<T>::node(const T& value):m_value(value), m_next(nullptr){
}

template <typename T>
int node<T>::getValue() const{
	return m_value;
}

template <typename T>
void node<T>::setValue(int value){
	m_value = value;
}

template <typename T>
node<T>* node<T>::getNext() const{
	return m_next;
}

template <typename T>
void node<T>::setNext(node<T>* nodeptr){
	m_next = nodeptr;
}
	
