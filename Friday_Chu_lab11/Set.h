#ifndef SET_H
#define SET_H

#include "Node_k.h"

class Set{
	private:
		 int len;
		 Node_k** nodes;
	public:
		Set(int length);
		~Set();
		void union_by_rank(int t1, int t2);
		Node_k* find(int label) const;
};

#endif
