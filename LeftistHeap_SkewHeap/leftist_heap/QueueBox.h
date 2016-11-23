#ifndef QUEUEBOX_H
#define QUEUEBOX_H

template <typename T>
class QueueBox{
	private:
		T m_item;
		QueueBox<T>* m_next;

	public:
		QueueBox();
		QueueBox(const T&);
		void setNext(QueueBox<T>*);
		QueueBox<T>* getNext() const;
		T getItem() const;
};

template <typename T>
QueueBox<T>::QueueBox(){
	m_next = nullptr;
}

template <typename T>
QueueBox<T>::QueueBox(const T& item){
	m_item = item;
	m_next = nullptr;
}

template <typename T>
void QueueBox<T>::setNext(QueueBox<T>* nextbox){
	m_next = nextbox;
}

template <typename T>
QueueBox<T>* QueueBox<T>::getNext() const{
	return m_next;
}

template <typename T>
T QueueBox<T>::getItem() const{
	return m_item;
}
#endif
