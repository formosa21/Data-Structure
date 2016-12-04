#ifndef HEAP_H
#define HEAP_H
#include <iostream>

template <typename T>
class Heap{
	// a min 5-heap
	private:
		const int k = 5; // a k-ary tree
		const int array_size = 16000000; // array used to fill the node values
		T **m_array;
		int m_nodes; // keeping track of how many nodes
		void push_down();
		void push_up(int index);
		int find_max_index() const;
		int find_x_index(T* x) const;
		int get_last_internal_index() const;

	public:
		Heap();
		~Heap();
		void constructive_insert(T* i); // use only for constructing initial heap
		void insert(T* i);
		void print() const; // print a level order heap
		void heapify_up();
		void heapify_compare_child_n_swap(int internal);
		void deleteMin();
		void deleteMax();
		void remove(T* x);
		bool isEmpty() const;
		void swap(int position1, int position2);

		//make it more like a PQ
		//These method works
		T* peek() const;
		T* pop();

};

#include "Heap.hpp"
#endif
