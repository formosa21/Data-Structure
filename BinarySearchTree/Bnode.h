#ifndef Bnode_H
#define Bnode_H

template <typename T>
class Bnode{
	private:
		Bnode<T> *m_right;
		Bnode<T> *m_left;
		T m_value;			
	public:
		Bnode();
		Bnode(T value); // creates a Bnode with value
		Bnode(const Bnode<T>& other); // creates a deep copy of another Bnode
		Bnode<T>*& getLeft();
		Bnode<T>*& getRight();
		T getValue() const;

		void setLeft(Bnode<T>*);
		void setRight(Bnode<T>*);
		void setValue(T);
};

template <typename T>
Bnode<T>::Bnode(): m_right(nullptr), m_left(nullptr){
}

template <typename T>
Bnode<T>::Bnode(T value): m_right(nullptr), m_left(nullptr), m_value(value){
}

template <typename T>
Bnode<T>::Bnode(const Bnode<T>& other){
}

template <typename T>
Bnode<T>*& Bnode<T>::getLeft(){
	return m_left;
}

template <typename T>
Bnode<T>*& Bnode<T>::getRight(){
	return m_right;
}

template <typename T>
T Bnode<T>::getValue() const{
	return m_value;
}

template <typename T>
void Bnode<T>::setLeft(Bnode<T>* left){
	m_left = left;
}

template <typename T>
void Bnode<T>::setRight(Bnode<T>* right){
	m_right = right;
}

template <typename T>
void Bnode<T>::setValue(T value){
	m_value = value;
}

#endif



