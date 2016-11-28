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
		~Min_Span_Tree();
		void kruskal();
		void prim();
		void prim_update_cost(int vertex_label); //once the vertex is inserted, we update it;
};



#endif
