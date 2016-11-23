#include "Heap.h"

Heap::Heap(){
	m_nodes = 0;
	for(int i = 0; i < array_size; i++)
		m_array[i] = -1;
}

Heap::Heap(const int size){
	for(int i = 0; i < array_size; i++)
		m_array[i] = -1;
	m_nodes = 0;
	array_size = size;
}

Heap::~Heap(){
	delete[] m_array;
}

void Heap::print() const{
	int exponent = 0;	
	for(int i = 0; i < m_nodes ; i++){
		std::cout << m_array[i] << " ";
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

void Heap::heapify_up(){
	// first internal node = floor ((n -2) / 5) ; for 5-ary tree
	// this is only executed when there are at least 2 nodes
	int internal = (m_nodes - 2) / 5;
	for(;internal >= 0; internal--){
		heapify_compare_child_n_swap(internal);
	}// end internal for loop
}

void Heap::heapify_compare_child_n_swap(int internal){
		//if it is a leaf
		if(m_array[(internal*5 + 1)] == -1)
			return;
		int furthest_internal = (m_nodes - 2) / 5;
		int min; // the index of the smallest ith child
		for(int i = 1; i <= k; i++){
			int ith_child = k*internal + i;
			if(m_array[ith_child] != -1){
				if(i == 1)
					min = ith_child;
				else{
					if(m_array[ith_child] < m_array[min])
						min = ith_child;
				}
			}
			else // m_array[ith_child] == -1; empty
				break;
		}// end child for loop
		if(m_array[min] < m_array[internal]){
			swap(internal, min); 
			if(internal <= (furthest_internal/5) ){ // only execute when an internal node's child is an internal node
				heapify_compare_child_n_swap(min); // check child internals recursively
			}
		}
}

void Heap::swap(int position1, int position2){
	int temp = m_array[position2];
	m_array[position2] = m_array[position1];
	m_array[position1] = temp; 
}

void Heap::constructive_insert(int i){
	m_array[m_nodes] = i;
	m_nodes++;
}

void Heap::insert(int i){
	int inserted_index = m_nodes;
	m_array[inserted_index] = i;
	m_nodes++;
	push_up(inserted_index);
}

void Heap::push_up(int index){
	if(m_array[index] == -1) // if the one got deleted is the last node; this will happen
		return;
	int parent_index = (index-1)/5;
	if(parent_index == 0){
		if(m_array[index] < m_array[parent_index])
			swap(index, parent_index);
	}
	else{
		if(m_array[index] < m_array[parent_index]){
			swap(index, parent_index);
			push_up(parent_index);
		}
	}

}

int Heap::find_max_index() const{
	int first_leaf = get_last_internal_index() + 1;

	int max = first_leaf;
	for(int i = first_leaf+1; i < m_nodes; ++i){
		if(m_array[i] > m_array[max])
			max = i;
	}
	return max;
}

int Heap::find_x_index(int x) const{
	for(int i = 0; i < m_nodes; ++i){
		if(m_array[i] == x)
			return i;
	}
	return -1; //failed; no number found
}

int Heap::get_last_internal_index() const{
	return (m_nodes - 2) / 5;
}

void Heap::deleteMin(){
	if(isEmpty())
		return;
	else{
		int furthest_node_index = m_nodes - 1;
		m_array[0] = m_array[furthest_node_index];
		m_array[furthest_node_index] = -1;
		heapify_compare_child_n_swap(0);
		m_nodes--;
	}
}

void Heap::deleteMax(){
	if(isEmpty())
		return;
	else{
		int max = find_max_index();
		m_array[max] = m_array[m_nodes - 1];
		m_array[m_nodes - 1] = -1;
		push_up(max);
		m_nodes--;
	}
}

void Heap::remove(int x){
	if(isEmpty())
		return;
	else{
		while(true){
			int index_x = find_x_index(x);
			// if number is found
			if(index_x >= 0){
				m_array[index_x] = m_array[m_nodes - 1];
				m_array[m_nodes - 1] = -1;
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

bool Heap::isEmpty() const{
	return (m_nodes == 0);
}
