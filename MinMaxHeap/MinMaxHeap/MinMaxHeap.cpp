#include "MinMaxHeap.h"

MinMaxHeap::MinMaxHeap(){
	m_elements = 0;
	for(int i = 0; i < array_size; i++){
		m_array[i] = -1;
	}
}

MinMaxHeap::~MinMaxHeap(){
	delete[] m_array;
}

void MinMaxHeap::constructive_insert(int i){
	//from index 1 instead of 0
	m_elements++;
	m_array[m_elements] = i;
}

void MinMaxHeap::heapify(){
	// first internal node = floor(n/2)-1
	// but since we use index 1 as the start..
	int internal = m_elements/2;
	for(; internal >= 1; internal--)
		TrickleDown(internal);
}

void MinMaxHeap::TrickleDown(int index){
	if(is_Min(index)) // even
		TrickleDownMin(index);
	else
		TrickleDownMax(index);
}

void MinMaxHeap::TrickleDownMin(int index){
	if(has_Children(index)){
		int m = getMinIndex_in_child_or_grandchild(index);
		if(is_grandchild(index, m)){
			if(m_array[m] < m_array[index]){
				swap(index, m);
				int parent_of_m = get_Parent_index(m);
				if(m_array[m] > m_array[parent_of_m]){
					swap(m, parent_of_m);
				}
				TrickleDownMin(m);
			}
		}
		else{ // is a child instead
			if(m_array[m] < m_array[index]){
				swap(index, m);
			}
		}
	}
	return;
}

void MinMaxHeap::TrickleDownMax(int index){
	if(has_Children(index)){
		int m = getMaxIndex_in_child_or_grandchild(index);

		if(is_grandchild(index, m)){
			if(m_array[m] > m_array[index]){
				swap(index, m);
				int parent_of_m = get_Parent_index(m);
				if(m_array[m] < m_array[parent_of_m]){
					swap(m, parent_of_m);
				}
				TrickleDownMax(m);
			}
		}
		else{ // is a child instead
			if(m_array[m] > m_array[index])
				swap(index, m);
		}
	}
	return;

}

bool MinMaxHeap::is_Min(int index) const{
	if((int) floor(log2(index)) % 2 == 0) // even; which is min level
		return true;
	return false;
}

bool MinMaxHeap::is_Max(int index) const{
	if(!is_Min(index))
		return true;
	return false;
}

int MinMaxHeap::getMinIndex_in_child_or_grandchild(int index) const{
	int a[6];
	a[0] = index * 2; //child_1_index
	a[1] = (a[0] + 1) < array_size ? a[0] + 1 : -1; //child_2_index
	a[2] = (a[0] * 2) < array_size ? a[0] * 2 : -1; //grandchild_1_from_c1
	a[3] = (a[2] + 1) < array_size ? a[2] + 1 : -1; //grandchild_2_from_c1
	a[4] = (a[1] * 2) < array_size ? a[1] * 2 : -1; //grandchild_1_from_c2
	a[5] = (a[4] + 1) < array_size ? a[4] * 1 : -1; //grandchild_2_from_c2

	int min = a[0];
	for(int i = 1; i < 6; i++){
		if(m_array[a[i]] == -1)
			break;
		else if(m_array[a[i]] < m_array[min])
			min = a[i];
	}
	return min; //return min index
}

int MinMaxHeap::getMaxIndex_in_child_or_grandchild(int index) const{
	int a[6];
	a[0] = index * 2; //child_1_index
	a[1] = (a[0] + 1) < array_size ? a[0] + 1 : -1; //child_2_index
	a[2] = (a[0] * 2) < array_size ? a[0] * 2 : -1; //grandchild_1_from_c1
	a[3] = (a[2] + 1) < array_size ? a[2] + 1 : -1; //grandchild_2_from_c1
	a[4] = (a[1] * 2) < array_size ? a[1] * 2 : -1; //grandchild_1_from_c2
	a[5] = (a[4] + 1) < array_size ? a[4] * 1 : -1; //grandchild_2_from_c2

	int max = a[0];
	for(int i = 1; i < 6; i++){
		if(m_array[a[i]] == -1)
			break;
		else if(m_array[a[i]] > m_array[max])
			max = a[i];
	}
	return max; //return min index
}


bool MinMaxHeap::has_Children(int index) const{
	if(m_array[index*2] != -1)
		return true;
	return false;
}

int MinMaxHeap::get_Parent_index(int index) const{
	return (index/2);
}

bool MinMaxHeap::has_Parent(int index) const{
	return (index/2 != 0);
}

bool MinMaxHeap::is_grandchild(int index1, int index2) const{
	if(index2 == (index1 * 2)*2 || index2 == (index1 * 2)*2 + 1)
		return true;
	return false;
}

int MinMaxHeap::get_gradnParent_index(int index) const{
	return (index/2)/2;
}

bool MinMaxHeap::has_grandParent(int index) const{
	return ((index/2)/2 != 0);
}

void MinMaxHeap::swap(int index1, int index2){
	int temp = m_array[index1];
	m_array[index1] = m_array[index2];
	m_array[index2] = temp;
}

void MinMaxHeap::levelOrder() const{
	int breakline = 1;
	for(int i = 1; i <= m_elements; i++){
		std::cout << m_array[i] << " ";
		if(i == breakline){
			std::cout << "\n";
			breakline = breakline*2 + 1;
		}
	}
	std::cout << "\n";
}

void MinMaxHeap::BubbleUp(int index){
	int parent_index = get_Parent_index(index);

	if(is_Min(index)){
		if(has_Parent(index) && m_array[index] > m_array[parent_index]){
			swap(index, parent_index);
			BubbleUpMax(parent_index);
		}
		else
			BubbleUpMin(index);
	}
	else{
		if(has_Parent(index) && m_array[index] < m_array[parent_index]){
			swap(index, parent_index);
			BubbleUpMin(parent_index);
		}
		else
			BubbleUpMax(index);
	}
}

void MinMaxHeap::BubbleUpMin(int index){
	int grandma = get_gradnParent_index(index);
	if(has_grandParent(index)){
		if(m_array[index] < m_array[grandma]){
			swap(index, grandma);
			BubbleUpMin(grandma);
		}
	}
}

void MinMaxHeap::BubbleUpMax(int index){
	int grandpa = get_gradnParent_index(index);
	if(has_grandParent(index)){
		if(m_array[index] > m_array[grandpa]){
			swap(index, grandpa);
			BubbleUpMax(grandpa);
		}
	}
}

void MinMaxHeap::insert(int element){
	//int inserted_index = m_elements + 1;
	m_array[m_elements+1] = element;
	m_elements++;
	BubbleUp(m_elements); // m_elements now is equivalent to the index of the element that just got inserted
}

void MinMaxHeap::deleteMin(){
	if(m_elements == 0)
		return;
	else if(m_elements == 1)
		m_array[1] = -1;
	else{
		m_array[1] = m_array[m_elements];
		m_array[m_elements] = -1;
		TrickleDownMin(1);
	}
	m_elements--;
}

void MinMaxHeap::deleteMax(){

	if(m_elements == 0)
		return;
	else if(m_elements == 1)
		m_array[1] = -1;
	else{
		if(m_array[2] > m_array[3]){
			m_array[2] = m_array[m_elements];
			m_array[m_elements] = -1;
			TrickleDownMax(2);
		}
		else if(m_array[3] > m_array[2]){
			m_array[3] = m_array[m_elements];
			m_array[m_elements] = -1;
			TrickleDownMax(3);
		}
		else{
			m_array[2] = m_array[m_elements];
			m_array[m_elements] = -1;
			TrickleDownMax(2);
		}
	}
	m_elements--;
}
