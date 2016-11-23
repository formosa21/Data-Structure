#ifndef HEAP_H
#define HEAP_H
#include <iostream>

class Heap{
	// a min 5-heap
	private:
		const int k = 5; // a k-ary tree
		const int array_size = 500; // array used to fill the node values
		int *m_array = new int[array_size];
		int m_nodes; // keeping track of how many nodes
		void push_down();
		void push_up(int index);
		int find_max_index() const;
		int find_x_index(int x) const;
		int get_last_internal_index() const;

	public:
		Heap();
		~Heap();
		void constructive_insert(int i); // use only for constructing initial heap
		void insert(int i);
		void print() const; // print a level order heap
		void heapify_up();
		void heapify_compare_child_n_swap(int internal);
		void deleteMin();
		void deleteMax();
		void remove(int x);
		bool isEmpty() const;
		void swap(int position1, int position2);

};

#endif
