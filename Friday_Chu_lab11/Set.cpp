#include "Set.h"

Set::Set(int length){
	len = length;
	nodes = new Node_k*[len];
	for(int i = 0; i< length; ++i)
		nodes[i] = new Node_k(i);

}

Set::~Set(){
	for(int i = 0; i < len; i++)
		delete nodes[i];
	delete[] nodes;
}

void Set::union_by_rank(int t1, int t2){
	if(nodes[t1]->get_rank() <= nodes[t2]->get_rank()){
		nodes[t1]->setParent(nodes[t2]);
		nodes[t2]->adjustRank();
	}
	else{
		nodes[t2]->setParent(nodes[t1]);
		nodes[t1]->adjustRank();
	}
}

Node_k* Set::find(int label) const{
	if(label >= len)
		return nullptr;
	else{
		int the_parent = label;
		Node_k* the_parent_node = nodes[label];
		while(nodes[the_parent]->get_parent() != nullptr){
			the_parent_node = nodes[the_parent]->get_parent();
			the_parent = the_parent_node->get_label();
		}
		return the_parent_node;
	}
}
