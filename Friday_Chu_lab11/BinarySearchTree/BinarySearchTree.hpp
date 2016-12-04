template<typename T>
BinarySearchTree<T>::BinarySearchTree(): m_root(nullptr){
	m_size = 0;
}

template<typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& other){
}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree(){
	if(m_root == nullptr){
	} else {
		deleteTree(m_root);
		m_root = nullptr;
	}
}

template<typename T>
bool BinarySearchTree<T>::isEmpty() const{
	return (m_root == nullptr);
}

template<typename T>
bool BinarySearchTree<T>::add(T value){
	m_size++;
	if(isEmpty()){
		m_root = new Bnode<T>(value);
		return true;
	} else {
		return add(value, m_root);
	}
}

template<typename T>
int BinarySearchTree<T>::size() const{
	return m_size;
}

template<typename T>
void BinarySearchTree<T>::printTree(Order order) const{
	printTree(m_root, order);
}


template<typename T>
Bnode<T>* BinarySearchTree<T>::search(T value){
	return search(value, m_root);
}

template<typename T>
bool BinarySearchTree<T>::find(T value) const{
	return (search(value, m_root) != nullptr) ? true : false;
}

template<typename T>
void BinarySearchTree<T>::deleteMin(){

	if(m_root == nullptr){
		return;
	}
	else{
		deleteMin(m_root);
		m_size--;
	}

}

template<typename T>
void BinarySearchTree<T>::deleteMax(){
	if(m_root == nullptr)
		return;
	else{
		deleteMax(m_root);
		m_size--;
	}
}

template<typename T>
void BinarySearchTree<T>::levelOrderTraverse() const{
	if(m_root != nullptr){
		Bnode<T>* passbyPtr;
		Queue<Bnode<T>*> qb;
		qb.enqueue(m_root);
		do{
			passbyPtr = qb.peek();
			std::cout << passbyPtr->getValue() << " ";
			if(qb.peek()->getLeft() != nullptr)
				qb.enqueue(qb.peek()->getLeft());
			if(qb.peek()->getRight() != nullptr)
				qb.enqueue(qb.peek()->getRight());
			qb.dequeue();

		}while(!qb.isEmpty());
	}
}

template<typename T>
Bnode<T>* BinarySearchTree<T>::getLeftMost(Bnode<T>* subtree) const{
	Bnode<T>* that_ptr = subtree;
	while(that_ptr->getLeft() != nullptr)
		that_ptr = that_ptr->getLeft();
	return that_ptr;
}

template<typename T>
Bnode<T>* BinarySearchTree<T>::getRightMost(Bnode<T>* subtree) const{
	Bnode<T>* that_ptr = subtree;
	while(that_ptr->getRight() != nullptr)
		that_ptr = that_ptr->getRight();
	return that_ptr;
}

template<typename T>
void BinarySearchTree<T>::remove(const T value){
	if(m_root == nullptr)
		return;
	else
		remove(value, m_root);
}


//private methods-----------------------------

template<typename T>
void BinarySearchTree<T>::remove(const T value, Bnode<T>*& subtree){
	if(value < subtree->getValue())
		remove(value, subtree->getLeft());
	else if(value > subtree->getValue())
		remove(value, subtree->getRight());
	else{
		if(subtree->getLeft() == nullptr && subtree->getRight() == nullptr){
			delete subtree;
			subtree = nullptr;
		}
		else if(subtree->getLeft() == nullptr){
			std::cout << "gotu!\n";
			Bnode<T>* temp = subtree;
			subtree = subtree->getRight();
			delete temp; temp = nullptr;
		}
		else if(subtree->getRight() == nullptr){
			Bnode<T>* temp = subtree;
			subtree = subtree->getLeft();
			delete temp; temp = nullptr;
		}
		else{
			Bnode<T>* temp = getLeftMost(subtree->getRight());
			subtree->setValue(temp->getValue());
			deleteMin(subtree->getRight());
		}
		m_size--;
	}
	return;
	/*
	T node_value = subtree->getValue();
	if(node_value != value){
		if(value < node_value && subtree->getLeft() != nullptr)
			remove(value, subtree->getLeft());
		else if(value > node_value && subtree->getRight() != nullptr)
			remove(value, subtree->getRight());
		else
			return;
	}
	else{ // value == node_value
		if(subtree->getLeft() == nullptr && subtree->getRight() == nullptr){
			delete subtree;
			subtree = nullptr;
		}
		else if(subtree->getLeft() != nullptr && subtree->getRight() != nullptr){
			Bnode<T>* smallest_val_node_on_rsb = getLeftMost(subtree->getRight());
			subtree->setValue(smallest_val_node_on_rsb->getValue());
			deleteMin(subtree->getRight());	//ok i know it's not perfect
		}
		else if(subtree->getLeft() != nullptr){
			Bnode<T>* temp = subtree;
			subtree = subtree->getLeft();
			delete temp; temp = nullptr;
		}
		else{
			Bnode<T>* temp = subtree;
			subtree = subtree->getRight();
			delete temp; temp = nullptr;
		}
	}*/
}


template<typename T>
bool BinarySearchTree<T>::add(T value, Bnode<T>* subtree){
	if(value < subtree->getValue()){
		if(subtree->getLeft() != nullptr)
			return add(value, subtree->getLeft());
		else{
			Bnode<T> *temp = new Bnode<T>(value);
			subtree->setLeft(temp);
			temp = nullptr;
			return true;
		}
	}
	else if(value > subtree->getValue()){
		if(subtree->getRight() != nullptr)
			return add(value, subtree->getRight());
		else{
			Bnode<T> *temp = new Bnode<T>(value);
			subtree->setRight(temp);
			temp = nullptr;
			return true;
		}
	}
	else // value == subtree->getValue()
		return false;
}

template<typename T>
void BinarySearchTree<T>::deleteTree(Bnode<T>* subtree){
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

template<typename T>
Bnode<T>* BinarySearchTree<T>::search(T value, Bnode<T>* subtree) const{
	if(subtree == nullptr)
		return nullptr;
	else if(subtree->getValue() == value)
		return subtree;
	else if(value < subtree->getValue())
		return search(value, subtree->getLeft());
	else //value > subtree->getValue()
		return search(value, subtree->getRight());

}

template<typename T>
void BinarySearchTree<T>::printTree(Bnode<T>* subtree, Order order) const{
	if(subtree == nullptr)
		return;

	switch(order){
		case PRE_ORDER:
			std::cout << subtree->getValue() << " ";
			printTree(subtree->getLeft(), order);
			printTree(subtree->getRight(), order);
			break;
		case IN_ORDER:
			printTree(subtree->getLeft(), order);
			std::cout << subtree->getValue() << " ";
			printTree(subtree->getRight(), order);
			break;
		case POST_ORDER:
			printTree(subtree->getLeft(), order);
			printTree(subtree->getRight(), order);
			std::cout << subtree->getValue() << " ";
			break;
		default:
			break;
	}

}

template<typename T>
void BinarySearchTree<T>::deleteMin(Bnode<T>* subtree){
	Bnode<T>* temp = subtree->getLeft();
	Bnode<T>* temp2 = subtree;
	if(temp == nullptr){
		Bnode<T>* temp3 = subtree;
		subtree = subtree->getRight();
		delete temp3;
		temp3 = nullptr;
	}
	else{
		while(temp->getLeft() != nullptr){
			temp2 = temp;
			temp = temp->getLeft();
		}

		if(temp->getRight() == nullptr){
			temp2->setLeft(nullptr);
		}
		else{//the min Bnode does have a right child (temp->getRight() != nullptr)
			Bnode<T>* temp3 = temp->getRight();
			temp2->setLeft(temp3);
			temp3 = nullptr;
		}
		delete temp;
	}
	temp = nullptr; temp2 = nullptr;
}

template<typename T>
void BinarySearchTree<T>::deleteMax(Bnode<T>* subtree){
	Bnode<T>* temp = subtree->getRight();
	Bnode<T>* temp2 = subtree;
	if(temp == nullptr){
		Bnode<T>* temp3 = subtree;
		subtree = subtree->getLeft();
		delete temp3;
		temp3 = nullptr;
	}
	else{
		while(temp->getRight() != nullptr){
			temp2 = temp;
			temp = temp->getRight();
		}

		if(temp->getLeft() == nullptr){
			temp2->setRight(nullptr);
		}
		else{//the min Bnode does have a left child (temp->getLeft() != nullptr)
			Bnode<T>* temp3 = temp->getLeft();
			temp2->setRight(temp3);
			temp3 = nullptr;
		}
		delete temp;
	}
	temp = nullptr; temp2 = nullptr;
}
