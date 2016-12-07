#include "Hash_Table.h"
#include <iostream>
using namespace std;

Hash_Table::Hash_Table(){
	m_table = nullptr;
	m_table_Size = 0;
}

Hash_Table::~Hash_Table(){
	delete[] m_table;
}

Hash_Table::Hash_Table(const int& size){
	m_table_Size = size;
	m_table = new Node[size];
	m_occupied = 0;
	//for(int i = 0; i < size; ++i){
	//	m_table[i] = Node();
	//}
}

int Hash_Table::size() const{
	return m_occupied;
}

void Hash_Table::insert(int x){
	if(isfull(x) /*|| contains(x)*/) // no use is this MST case
		return;

	// for non-duplicated keys only
	// check the location (length of table) times
	m_occupied++;
	int prob = 0;
	int pos;
	bool mark = false; // has position that has value = -1 but flag = true
	int mark_pos; // mark that location that has value = -1 but flag = true
	for(int i = 0; i < m_table_Size; ++i){
		pos = hash(x, prob);
		if(!mark){ // if the position that has value = -1 but flag = true has encoutered, it will not check this block again
			if(m_table[pos].getValue() == -1 && m_table[pos].getFlag() == true){
				mark = true;
				mark_pos = pos;
			}
		}

		if(m_table[pos].getValue() == -1 && m_table[pos].getFlag() == false){
			m_table[pos].setValue(x);
			mark = false; // value inserted; mark set to false so that we don't insert the value again
			break;
		}
		else{
			prob++;
		}
	}

	if(mark){
		m_table[mark_pos].setValue(x);
	}
}

void Hash_Table::remove(int x){
	int prob = 0;
	int pos;
	for(int i = 0; i < m_table_Size; ++i){
		pos = hash(x, prob);
		if(m_table[pos].getValue() == x){
			m_table[pos].setValue(-1);
			m_table[pos].setFlag(); // set flag to true
			m_occupied--;
			break;
		}
		else if(m_table[pos].getValue() == -1 && !m_table[pos].getFlag())
			break; // if empty, and getFlag == false, then stop
		else{
			prob++;
		}
	}
}

int Hash_Table::hash(const int& x, const int& increment) const{
	return ((x % m_table_Size) + increment*increment) % m_table_Size;
}

void Hash_Table::print() const{
	for(int i = 0; i < m_table_Size; ++i){
		cout << i << ": " << m_table[i].getValue()
			<< " flag=" << m_table[i].printFlag() << endl;
	}
}

bool Hash_Table::contains(const int& x) const{
	int prob = 0;
	int pos;
	for(int i = 0; i < m_table_Size; ++i){
		pos = hash(x, prob);
		if(m_table[pos].getValue() == x){
			return true;
		}
		else
			prob++;
	}
	return false;
}

bool Hash_Table::isfull(const int& x) const{
	int prob = 0, pos;
	bool full = true;
	for(int i = 0; i < m_table_Size; ++i){
		pos = hash(x, prob);
		if(m_table[pos].getValue() == -1){
			full = false;
			break;
		}else{
			prob++;
		}

	}
	return full;

}
