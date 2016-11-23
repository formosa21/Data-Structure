#ifndef MIN_SPAN_TREE_H
#define MIN_SPAN_TREE_H

#include "Set.h"
#include "./Min5Heap/Heap.h"
#include "./Linkedlist/linkedlist.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstring>

#define show() std::cout << "here!!!\n";

class Min_Span_Tree{
	private:
		struct edge{
			int cost;
			int x;
			int y;
			bool operator > (const edge& a){
				return (cost > a.cost ? true : false);
			}
			bool operator < (const edge& a){
				return (cost < a.cost ? true : false);
			}
			bool operator == (const edge& a){
				return (cost == a.cost ? true : false);
			}
			bool operator <= (const edge& a){
				return (cost <= a.cost ? true : false);
			}
			bool operator >= (const edge& a){
				return (cost >= a.cost ? true : false);
			}
			void operator = (const edge& a){
				cost = a.cost;
				x = a.x;
				y = a.y;
			}
			friend std::ostream& operator << (std::ostream& os, const edge& a){
				os << a.cost;
				return os;
			}

		};

		struct vertex{
			int label;
			int *cost; // min(v): minimum cost from this vertex to a vertex in vertex set //changes depend on operation
			int *other; // u in V_t such that cost(v,u) = min(v);

			bool operator == (const vertex& v){
				return (label == v.label ? true : false);
			}
			friend std::ostream& operator << (std::ostream& os, const vertex& a){
				os << a.label;
				return os;
			}
		};

		int **adj_matrix;
		Heap<edge> pq;
		vertex *vertices;
		linkedlist<int> *v_t = new linkedlist<int>(); //lable of vertices
		int dimension;
		int inf = 99999;
	public:		
		Min_Span_Tree();
		void kruskal();
		void prim();
		void prim_update_cost(int vertex_label); //once the vertex is inserted, we update it;
};

Min_Span_Tree::Min_Span_Tree(){

	std::ifstream read;
	read.open("data.txt");
	std::string line;
	std::getline(read, line);
	int matrices_count = atoi(line.c_str());

	for(int i = 0; i < matrices_count; i++){
		std::getline(read, line);
		dimension = atoi(line.c_str());
		adj_matrix = new int*[dimension];
		for(int j = 0; j < dimension; j++)
			adj_matrix[j] = new int[dimension];
		
		for(int k = 0; k < dimension; k++){
			std::getline(read, line);
			char *token = strtok((char*)line.c_str(), " ");
			int j = 0;
			do{
				if(token != nullptr)
					adj_matrix[k][j] = atoi(token);
				token = strtok(NULL, " ");
				j++;
			}while(token != nullptr);
		}
		for(int k = 0; k < dimension; k++){
			for(int j = 0; j < dimension; j++){
				std::cout << adj_matrix[k][j] << " ";
			}
			std::cout << "\n";
		}
		std::cout << "\n";
		
		kruskal();
		prim();

		for(int i = 0; i < dimension; i++){
			delete vertices[i].cost; vertices[i].cost = nullptr;
			delete vertices[i].other; vertices[i].other = nullptr;
		}
		delete[] vertices;
		delete v_t; v_t = new linkedlist<int>();
		delete[] adj_matrix; delete adj_matrix; adj_matrix = nullptr;
	}

	read.close();
	delete v_t;
		
}


void Min_Span_Tree::kruskal(){
	//queue the edges
	for(int i = 0; i < dimension; i++){
		for(int j = 0; j < dimension; j++){
			if(adj_matrix[i][j] != 0){
				edge *e = new edge(); e->x = i; e->y = j; e->cost = adj_matrix[i][j];
				pq.insert(e);
			}
		}
	}
	//pq.print();

	edge *min_span_tree[dimension -1];
	int inserted_edge_count = 0;
	Set the_set = Set(dimension);
	while(!pq.isEmpty() && inserted_edge_count != (dimension-1)){
		edge *e = pq.pop(); 
		//std::cout << "Inserting (" << e->x << ", " << e->y << ") \n";
		
		if(the_set.find(e->x) != the_set.find(e->y)){
			min_span_tree[inserted_edge_count] = e;
			inserted_edge_count++;
			the_set.union_by_rank(the_set.find(e->x)->get_label(), the_set.find(e->y)->get_label());	
			//std::cout << "Insertion complete\n";
		}
		else{
			delete e; e = nullptr;
		}
	}

	for(int i = 0; i < dimension -1; i++)
		std::cout << "(" << min_span_tree[i]->x << ", " << min_span_tree[i]->y << ")";
	std::cout << "\n";	
	for(edge *i : min_span_tree){ delete i; i = nullptr;}
}

void Min_Span_Tree::prim(){

	edge *min_span_tree[dimension -1];
	int inserted_edge_count = 0;
	//initialize set of vertices
	vertices = new vertex[dimension];
	for(int i = 0; i < dimension; i++){
		vertices[i].label = i;
		vertices[i].cost = new int[dimension];
		vertices[i].other = new int[dimension];

		for(int j = 0; j < dimension; j++){
			vertices[i].cost[j] = inf;
			vertices[i].other[j] = j;
		}
	}

	//set V_t = {0}; 
	v_t->insert(vertices[0].label);
	prim_update_cost(vertices[0].label);

	v_t->print();
	std::cout << "\n";	

	while(v_t->size() < dimension){
		int min = inf;
		vertex *w = nullptr;
		int other_index;
		for(int i = 1; i < dimension; i++){
			if(v_t->find(vertices[i].label))
				continue;
			else{
				for(int j = 0; j < dimension; j++){
					if(!v_t->find(vertices[j].label))
						continue;	
					else{
						if(vertices[i].cost[j] < min){
							min = vertices[i].cost[j];
							w = &vertices[i];	
							other_index = j; //other vertex's index
						}
					}
				}
			}
		}

		if(w != nullptr)
			v_t->insert((*w).label); // might be a problem if no vertex is selected;

		edge *e = new edge(); e->x = (*w).label; e->y = other_index; e->cost = (*w).cost[other_index];
		min_span_tree[inserted_edge_count] = e;	
		inserted_edge_count++;
		prim_update_cost(other_index);
		v_t->print();
		std::cout << "\n";	
	}//end while
	for(int i = 0; i < dimension -1; i++)
		std::cout << "(" << min_span_tree[i]->x << ", " << min_span_tree[i]->y << ")";
	std::cout << "\n";	
	for(edge *i : min_span_tree){ delete i; i = nullptr;}

}

void Min_Span_Tree::prim_update_cost(int vertex_label){
	for(int i = 0; i < dimension; i++){
		if(i == vertex_label){
			for(int j = 0; j < dimension; j++){
				vertices[i].cost[j] = inf;
			}
		}
		else{
			for(int j = 0; j < dimension; j++){
				if(!v_t->find(vertices[j].label))
					continue;
				else{
					if(vertices[i].cost[j] > adj_matrix[i][j] && adj_matrix[i][j] != 0)
						vertices[i].cost[j] = adj_matrix[i][j];
				}
			}
		}
	}
}

#endif
