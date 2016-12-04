#include "Node_k.h"
Node_k::Node_k(int label_val){
	label = label_val;
}

int Node_k::get_label() const{
	return label;
}

int Node_k::get_rank() const{
	return rank;
}

Node_k* Node_k::get_parent() const{
	return parent;
}

void Node_k::setParent(Node_k* parentPtr){
	parent = parentPtr;
}

void Node_k::adjustRank(){
	rank++;
}

