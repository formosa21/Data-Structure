#ifndef Node_k_H
#define Node_k_H

class Node_k{
	private:	
		int label;
		Node_k *parent = nullptr;
		int rank = 0;

	public:
		Node_k(int);
		int get_label() const;
		int get_rank() const;
		Node_k *get_parent() const;
		void setParent(Node_k*);
		void adjustRank();

	

};



#endif
