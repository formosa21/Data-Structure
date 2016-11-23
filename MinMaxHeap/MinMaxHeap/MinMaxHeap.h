#ifndef MINMAXHEAP_H
#define MINMAXHEAP_H

#include <math.h>
#include <iostream>

//important: discard 0 index; start from index 1
//-- this will be easier for calculation purposes such as locating min max level
//
//reminder: MinMaxHeap is a complete binary tree

class MinMaxHeap{
	private:
		const int array_size = 800001;
		int *m_array = new int[array_size];
		int m_elements; //keeping track of how many elements in the heap

		//helper functions
		bool is_grandchild(int index, int index2) const; //check if index2 is a grandchild of index1
		bool has_Children(int index) const;
		int get_Parent_index(int index) const;
		bool has_Parent(int index) const;
		int get_gradnParent_index(int index) const;
		bool has_grandParent(int index) const;
		int getMinIndex_in_child_or_grandchild(int index) const; // index of smallest of the children and grandchildren
		int getMaxIndex_in_child_or_grandchild(int index) const; // index of largest of the children and grandchildren
		bool is_Max(int) const; // if it's at a Max level
		bool is_Min(int) const; // if it's at a Min level
		void swap(int, int);

		//standard algorithms following the minmax paper
		void TrickleDown(int);
		void TrickleDownMin(int);
		void TrickleDownMax(int);
		void BubbleUp(int);
		void BubbleUpMin(int);
		void BubbleUpMax(int);

	public:
		MinMaxHeap();
		~MinMaxHeap();
		void constructive_insert(int); //for heapify operation
		void heapify(); //build; bottom-up approach
		void insert(int);
		void deleteMin();
		void deleteMax();
		void levelOrder() const;

};

#endif
