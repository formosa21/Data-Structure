#ifndef QUEUE_H
#define QUEUE_H

#include "QueueBox.h"

template <typename T>
class Queue{
	private:
		int m_size;
		QueueBox<T>* m_front;
		QueueBox<T>* m_back;

	public:
		Queue();
		~Queue();
		void enqueue(const T);
		void dequeue();
		T peek() const;
		int size() const;
		bool isEmpty() const;

		
};

template <typename T>
Queue<T>::Queue(){
	m_size = 0;
	m_front = nullptr;
	m_back = nullptr;
}

template <typename T>
Queue<T>::~Queue(){
	while(!isEmpty())
		dequeue();
}

template <typename T>
void Queue<T>::enqueue(const T stuff){
	QueueBox<T>* temp = new QueueBox<T>(stuff);
	if(!isEmpty()){
		m_back->setNext(temp);
		m_back = temp;
	}
	else{
		m_front = temp;
		m_back = m_front;
	}
	m_size++;
}

template <typename T>
void Queue<T>::dequeue(){
	if(!isEmpty()){
		QueueBox<T>* rm = m_front;
		m_front = m_front->getNext();
		delete rm;
	}
	m_size--;
}

template <typename T>
T Queue<T>::peek() const{
	return m_front->getItem();
}

template <typename T>
int Queue<T>::size() const{
	return m_size;
}

template <typename T>
bool Queue<T>::isEmpty() const{
	if(m_size == 0)
		return true;
	return false;
}

#endif
