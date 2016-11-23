#ifndef NODE_H
#define NODE_H

class Node{
	private:
		Node *m_left;
		Node *m_right;
		int m_rank;
		int m_value; //key; as described in pseudo code
		int adjustRank_helper(Node*, Node*);
	public:
		Node();
		Node(int);
		int getValue() const;
		int getRank() const;
		Node *getLeft() const;
		Node *getRight() const;
		void setValue(int value);
		void setLeft(Node*);
		void setRight(Node*);
		void adjustRank();
		bool isNull() const; // if both m_left & m_right are nullptrs
};

Node::Node(){
	m_value = 0;
	m_left = nullptr;
	m_right = nullptr;
	m_rank = 1;
}

Node::Node(int value){
	m_value = value;
	m_left = nullptr;
	m_right = nullptr;
	m_rank = 1;
}

int Node::getValue() const{
	return m_value;
}

int Node::getRank() const{
	return m_rank;
}

Node* Node::getLeft() const{
	return m_left;
}

Node* Node::getRight() const{
	return m_right;
}

void Node::setValue(int value){
	m_value = value;
}

void Node::setLeft(Node* left_ptr){
	m_left = left_ptr;
}

void Node::setRight(Node* right_ptr){
	m_right = right_ptr;
}

bool Node::isNull() const{
	return (m_left == nullptr && m_right == nullptr);
}

void Node::adjustRank(){
	if(isNull()){
		m_rank = 1; // maybe doesn't need this line; or need it (child removed)
		return;
	}
	m_rank += adjustRank_helper(getLeft(), getRight());
}

int Node::adjustRank_helper(Node *n1, Node *n2){
	int child_rank = 1;
	if(n1 == nullptr)
		return child_rank;
	else if(n2 == nullptr)
		return child_rank;
	else{
		Node *left = n1;
		Node *right = n2;
		int lchild_rank = 1; int rchild_rank = 1;
		while(left->getLeft() != nullptr){
			lchild_rank++;
			left = left->getLeft();
		}
		while(right->getRight() != nullptr){
			rchild_rank++;
			right = right->getRight();
		}
		
		if(lchild_rank < rchild_rank)
			child_rank += lchild_rank;
		else
			child_rank += rchild_rank;
	}

	return child_rank;
}
#endif
