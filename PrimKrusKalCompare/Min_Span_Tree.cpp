#include "Min_Span_Tree.h"
#include "./Timer/Timer.cpp"
#include <iostream>

Min_Span_Tree::Min_Span_Tree(){
	int test_set[] = {500, 1000, 2000, 4000};
	std::ofstream write;
	write.open("result.txt");
	int matrices_count = 4;
	Timer my_timer;
	double duration;
	double generated;


	for(int i = 0; i < matrices_count; i++){
		dimension = test_set[i];
		adj_matrix = new int*[dimension];
		pq = new Heap<edge>();

		for (int o = 1; o <= 1; o++){
			srand(o);
			for(int j = 0; j < dimension; j++)
				adj_matrix[j] = new int[dimension];
			for(int k = 0; k < dimension; k++){
				for(int j = 0; j < dimension; j++){
						generated = static_cast<double>(rand()) / RAND_MAX;
						adj_matrix[k][j] = (generated >= 0 && generated < 0.5) ? inf : (rand()%(4*dimension) + 1);
						//if(adj_matrix[k][j] > 99999)
							//std::cout << adj_matrix[k][j] << " ";
				}
			}
			/*
			for(int k = 0; k < dimension; k++){
				for(int j = 0; j < dimension; j++){
					std::cout << adj_matrix[k][j] << " ";
				}
				std::cout << "\n";
			}
			*/
				//write << "Graph "<< i <<": \n";
			//std::cout << "Dimension: " << dimension << "\n";

				my_timer.start();
				kruskal();
				duration = my_timer.stop();
				write << "kruskal " << i << ": " << duration << "\n";
				my_timer.start();
				prim();
				duration = my_timer.stop();
				write << "Prim " << i << ": " << duration << "\n";
				write << "---------\n";

				for(int h = 0; h < dimension; h++){
						delete[] adj_matrix[h];
						if(vertices != nullptr){
							delete[] vertices[h].cost;
							delete[] vertices[h].other;
						}
				}
				delete v_t; v_t = new BinarySearchTree<int>();
				if(vertices != nullptr) delete[] vertices;
				delete[] adj_matrix;
		}

	}
	//
	//delete v_t;
	write.close();
}

Min_Span_Tree::~Min_Span_Tree(){

}

void Min_Span_Tree::kruskal(){
	//queue the edges
	for(int i = 0; i < dimension; i++){
		for(int j = 0; j < dimension; j++){
			//std::cout << "inserting at position [" << i << "][" << j << "]\n";
			if(adj_matrix[i][j] != 0){
				edge *e = new edge(); e->x = i; e->y = j; e->cost = adj_matrix[i][j];
				pq->insert(e);
				//std::cout << "inserting: " << i << ", " << j << "\n";
			}
		}
	}
	//pq.print();

	edge *min_span_tree[dimension -1];
	int inserted_edge_count = 0;
	Set the_set = Set(dimension);
	while(!pq->isEmpty() && inserted_edge_count != (dimension-1)){
		edge *e = pq->pop();
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
	/*
	std::cout << "Kruskal: ";
	for(int i = 0; i < dimension -1; i++)
		std::cout << "(" << min_span_tree[i]->x << ", " << min_span_tree[i]->y << ")";
		*/

	for(edge *i : min_span_tree){ delete i; i = nullptr;}
}

void Min_Span_Tree::prim(){
	//std::cout << "hi! dimension " << dimension << "\n";
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

	bool* is_in_set = new bool[dimension];
	for(int i = 0; i < dimension; i++){
		is_in_set[i] = false;
	}
	//set V_t = {0};
	v_t->add(vertices[0].label);
	is_in_set[0] = true;
	prim_update_cost(vertices[0].label, is_in_set);

	//v_t->print();
	//std::cout << "\n";

	while(v_t->size() < dimension){
		int min = inf;
		vertex *w = nullptr;
		int other_index;

		for(int i = 1; i < dimension; ++i){
				// this should skip the vertices that are already in the set
				if(!is_in_set[i]){//this should skip the vertices that are already in the set
					//std::cout << "waiting find process 2\n";
					for(int j = 0; j < dimension; ++j){
						if(adj_matrix[i][j] < min && is_in_set[j]){//vertex i not in the set, vertex j in the set
								min = adj_matrix[i][j];
								w = &vertices[i];
								other_index = j; //other vertex's index
						}
					}
				}
		}



		if(w != nullptr)
			v_t->add((*w).label); // might be a problem if no vertex is selected;
		is_in_set[(*w).label]	= true;
		edge *e = new edge(); e->x = (*w).label; e->y = other_index; e->cost = (*w).cost[other_index];
		min_span_tree[inserted_edge_count] = e;
		inserted_edge_count++;
		prim_update_cost(other_index, is_in_set);
		//v_t->print();
		//std::cout << "\n";
	}//end while

	/*
	std::cout << "Prim: ";
	for(int i = 0; i < dimension -1; i++)
		std::cout << "(" << min_span_tree[i]->x << ", " << min_span_tree[i]->y << ")";
	std::cout << "\n\n";
	*/
	for(edge *i : min_span_tree){ delete i; i = nullptr;}

}

void Min_Span_Tree::prim_update_cost(int vertex_label, bool in_set[]){
	for(int i = 0; i < dimension; i++)
		vertices[vertex_label].cost[i] = inf;
	for(int i = 0; i < dimension; i++){
		if(!in_set[i]){
			//std::cout << "waiting find process 3\n";
			for(int j = 0; j < dimension; j++){
				if(vertices[i].cost[j] > adj_matrix[i][j] && adj_matrix[i][j] != 0)
					vertices[i].cost[j] = adj_matrix[i][j];
			}
		}
		/*
		if(i == vertex_label){
			for(int j = 0; j < dimension; j++){
				vertices[i].cost[j] = inf;
			}
		}
		else{
			for(int j = 0; j < dimension; j++){
				if(!in_set[j]){
					std::cout << "waiting find process 3\n";
					continue;
				}
				else{
					if(vertices[i].cost[j] > adj_matrix[i][j] && adj_matrix[i][j] != 0)
						vertices[i].cost[j] = adj_matrix[i][j];
				}
			}//end for
		}
	*/
	}//end for

}
