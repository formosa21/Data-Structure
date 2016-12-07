#ifndef Hash_Table_H
#define Hash_Table_H

#include "Node.h"

class Hash_Table{
	private:
		Node* m_table;
		int m_table_Size;
		int m_occupied;
	public:
		Hash_Table();
		~Hash_Table();
		Hash_Table(const int& size); //size = prime number
		void insert(int x);
		void remove(int x);
		int hash(const int& x, const int& increment) const;
		void print() const;
		bool contains(const int& x) const;
		bool isfull(const int&) const;
		int size() const;
};
#endif
