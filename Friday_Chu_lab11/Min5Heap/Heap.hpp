template <typename T>
Heap<T>::Heap(){
	m_nodes = 0;
	m_array = new T*[array_size];
	for(int i = 0; i < array_size; i++)
		m_array[i] = nullptr;
}

template <typename T>
Heap<T>::~Heap(){
	for(int i = 0; i < array_size; i++)
		delete m_array[i];
	delete[] m_array;
}

template <typename T>
void Heap<T>::print() const{
	int exponent = 0;
	for(int i = 0; i < m_nodes ; i++){
		std::cout << *m_array[i] << " ";
		if(i == 0){
			std::cout << "\n";
		}
		else if(i % 5 == 0 && i != m_nodes-1){
			int exp = 5;
			for(int i = 0; i < exponent; i++)
				exp *= 5;
			if(i / exp == 1)
				std::cout << "\n";
			else
				std::cout << "- ";
			exponent++;
		}

	}
	std::cout << "\n";
}

template <typename T>
void Heap<T>::heapify_up(){
	// first internal node = floor ((n -2) / 5) ; for 5-ary tree
	// this is only executed when there are at least 2 nodes
	int internal = (m_nodes - 2) / 5;
	for(;internal >= 0; internal--){
		heapify_compare_child_n_swap(internal);
	}// end internal for loop
}

template <typename T>
void Heap<T>::heapify_compare_child_n_swap(int internal){
		//if it is a leaf
		if(m_array[(internal*5 + 1)] == nullptr)
			return;
		int furthest_internal = (m_nodes - 2) / 5;
		int min; // the index of the smallest ith child
		for(int i = 1; i <= k; i++){
			int ith_child = k*internal + i;
			if(m_array[ith_child] != nullptr){
				if(i == 1)
					min = ith_child;
				else{
					if(*m_array[ith_child] < *m_array[min])
						min = ith_child;
				}
			}
			else // m_array[ith_child] == nullptr; empty
				break;
		}// end child for loop
		if(*m_array[min] < *m_array[internal]){
			swap(internal, min);
			if(internal <= (furthest_internal/5) ){ // only execute when an internal node's child is an internal node
				heapify_compare_child_n_swap(min); // check child internals recursively
			}
		}
}

template <typename T>
void Heap<T>::swap(int position1, int position2){
	T* temp = m_array[position2];
	m_array[position2] = m_array[position1];
	m_array[position1] = temp;
}

template <typename T>
void Heap<T>::constructive_insert(T* i){
	m_array[m_nodes] = i;
	m_nodes++;
}

template <typename T>
void Heap<T>::insert(T* i){
	int inserted_index = m_nodes;
	m_array[inserted_index] = i;
	m_nodes++;
	push_up(inserted_index);
}

template <typename T>
void Heap<T>::push_up(int index){
	if(m_array[index] == nullptr) // if the one got deleted is the last node; this will happen
		return;
	int parent_index = (index-1)/5;
	if(parent_index == 0){
		if(*m_array[index] < *m_array[parent_index])
			swap(index, parent_index);
	}
	else{
		if(*m_array[index] < *m_array[parent_index]){
			swap(index, parent_index);
			push_up(parent_index);
		}
	}

}

template <typename T>
int Heap<T>::find_max_index() const{
	int first_leaf = get_last_internal_index() + 1;

	int max = first_leaf;
	for(int i = first_leaf+1; i < m_nodes; ++i){
		if(*m_array[i] > *m_array[max])
			max = i;
	}
	return max;
}

template <typename T>
int Heap<T>::find_x_index(T* x) const{
	for(int i = 0; i < m_nodes; ++i){
		if(m_array[i] == x)
			return i;
	}
	return -1; //failed; no number found
}

template <typename T>
int Heap<T>::get_last_internal_index() const{
	return (m_nodes - 2) / 5;
}

template <typename T>
void Heap<T>::deleteMin(){
	if(isEmpty())
		return;
	else{
		int furthest_node_index = m_nodes - 1;
		delete *m_array[0];
		*m_array[0] = *m_array[furthest_node_index];
		delete m_array[furthest_node_index];

		m_array[furthest_node_index] = nullptr;
		heapify_compare_child_n_swap(0);
		m_nodes--;
	}
}

template <typename T>
void Heap<T>::deleteMax(){
	if(isEmpty())
		return;
	else{
		int max = find_max_index();
		m_array[max] = m_array[m_nodes - 1];
		delete m_array[m_nodes - 1];
		m_array[m_nodes - 1] = nullptr;
		push_up(max);
		m_nodes--;
	}
}

template <typename T>
void Heap<T>::remove(T* x){
	if(isEmpty())
		return;
	else{
		while(true){
			int index_x = find_x_index(x);
			// if number is found
			if(index_x >= 0){
				m_array[index_x] = m_array[m_nodes - 1];
				delete m_array[m_nodes - 1];
				m_array[m_nodes - 1] = nullptr;
				m_nodes--;
				// if index_x is a leaf
				if(index_x > get_last_internal_index())
					push_up(index_x);
				else
					heapify_compare_child_n_swap(index_x);
			}
			else
				break;
		} // so that every duplicates get removed
	}
}

template <typename T>
bool Heap<T>::isEmpty() const{
	return (m_nodes == 0);
}

template <typename T>
T* Heap<T>::peek() const{
	return m_array[0];
}

template <typename T>
T* Heap<T>::pop(){
	if(isEmpty())
		return nullptr;
	else{
		int furthest_node_index = m_nodes - 1;
		T* temp = m_array[0];
		m_array[0] = m_array[furthest_node_index];
		m_array[furthest_node_index] = nullptr;
		heapify_compare_child_n_swap(0);
		m_nodes--;
		return temp;
	}
}
