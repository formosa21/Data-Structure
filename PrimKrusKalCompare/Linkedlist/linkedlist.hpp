#include "linkedlist.h"

template <typename T>
linkedlist<T>::linkedlist(): m_first(nullptr), m_size(0){
}

template <typename T>
linkedlist<T>::~linkedlist(){
	if(isEmpty()){
	} 
	else if(m_size == 1){
		delete m_first;
		m_first = nullptr;
	}
	else{
		node<T>* temp = m_first->getNext();
		delete m_first;
		m_first = nullptr;
		while(temp != nullptr){
			node<T>* temp2= temp;
			temp = temp->getNext();
			delete temp2;
			temp2 = nullptr;
		}
		m_size = 0;
		temp = nullptr;
	}
}

template <typename T>
int linkedlist<T>::size() const{
	return m_size;
}

template <typename T>
bool linkedlist<T>::isEmpty() const{
	if(m_size == 0)
		return true;
	return false;
}

template <typename T>
void linkedlist<T>::print() const{
	if(isEmpty()){
		std::cout << "List empty!";
	}else{
		node<T>* temp = m_first;
		int i = 1;
		std::cout << "List: ";
		while(temp != nullptr){
			std::cout << temp->getValue() << " ";
			temp = temp->getNext();
			i++;
		}
		temp = nullptr;
	}
}

template <typename T>
void linkedlist<T>::insert(const T& value){
	node<T>* temp = new node<T>(value);
	if(isEmpty()){
		m_first = temp;
		temp = nullptr;
	}
	else{
		node<T>* temp2 = m_first;
		while(temp2->getNext() != nullptr){
			temp2 = temp2->getNext();
		}
		temp2->setNext(temp);	
		temp2 = nullptr;
		temp = nullptr;
	}
	m_size++;
}

template <typename T>
void linkedlist<T>::erase(const T& value){
	for(int i = 0; i < m_size; i++){
		node<T>* go = find(value);
		if(go == nullptr){
			break; //break from for loop
		}else{
			if(go == m_first){
				m_first = m_first->getNext();
			}
			else{
				node<T>* go2 = m_first;
				while(go2->getNext()->getNext() != go){
					go2 = go2->getNext();	
				}
				go2 = go2->getNext();
				go2->setNext(go->getNext());
				go2 = nullptr;
			}
			delete go; go = nullptr;
			m_size--;
		}
	}
}

template <typename T>
bool linkedlist<T>::find(const T& value) const{
	node<T>* go = m_first;
	while(go != nullptr){
		if(go->getValue() == value)
			return true;
		go = go->getNext();
	}
	return false;
}

template <typename T>
void linkedlist<T>::reverse(){
	if(m_size == 1){
	}
	else{
		T value = m_first->getValue();
		removeFront();
		reverse(); //recursion
		insert(value);
	}
	return;
}

template <typename T>
void linkedlist<T>::removeFront(){
	if(isEmpty()){
	} else {
		node<T>* temp = m_first;
		m_first = m_first->getNext();
		delete temp;
		temp = nullptr;
		m_size--;
	}
}

template <typename T>
void linkedlist<T>::concatenate(node<T>* thislist_ptr, node<T>* otherlist_start_ptr){
	if(thislist_ptr->getNext() != nullptr)
		concatenate(thislist_ptr->getNext(), otherlist_start_ptr); // go to the last node recursively
	else{
		int size;
		node<T>* temp = otherlist_start_ptr;
		while(temp->getNext()!= nullptr){
			temp = temp->getNext();
			size++;	
		}
		m_size += (size + 1); // to account the last node

		thislist_ptr->setNext(otherlist_start_ptr);
	}
}

template <typename T>
node<T>* linkedlist<T>::getfirst() const{
	return m_first;
}




