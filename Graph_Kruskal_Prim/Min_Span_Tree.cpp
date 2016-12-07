#include "Min_Span_Tree.h"

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
		/*
		for(int k = 0; k < dimension; k++){
			for(int j = 0; j < dimension; j++){
				std::cout << adj_matrix[k][j] << " ";
			}
			std::cout << "\n";
		}
		*/
		std::cout << "Graph "<< i <<": \n";

		kruskal();
		prim();


		delete v_t; v_t = new linkedlist<int>();
		for(int i = 0; i < dimension; i++){
				delete[] adj_matrix[i];
				delete[] vertices[i].cost;
				delete[] vertices[i].other;
		}
		delete[] vertices;
		delete[] adj_matrix;
	}

	read.close();
	delete v_t;

}

Min_Span_Tree::~Min_Span_Tree(){

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
	std::cout << "Kruskal: ";
	for(int i = 0; i < dimension -1; i++)
		std::cout << "(" << min_span_tree[i]->x << ", " << min_span_tree[i]->y << ")";
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

	bool is_in_set[dimension];
	for(int i = 0; i < dimension; i++){
		is_in_set[i] = false;
	}
	//set V_t = {0};
	v_t->insert(vertices[0].label);
	is_in_set[0] = true;
	prim_update_cost(vertices[0].label, is_in_set);

	//v_t->print();
	std::cout << "\n";

	while(v_t->size() < dimension){
		int min = inf;
		vertex *w = nullptr;
		int other_index;

		for(int i = 0; i < dimension; i++){
			// this should skip the vertices that are already in the set
			if(is_in_set[i]) //if the vertex is included in the set; like if we start at vertex 1, then vertex 1 is in the set
				continue;
			else{ //this should skip the vertices that are already in the set
				for(int j = 0; j < dimension; j++){
					if(!is_in_set[j]) // if the vertex is not in the set
						continue;
					else{//vertex i not in the set, vertex j in the set
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
		is_in_set[(*w).label]	= true;
		edge *e = new edge(); e->x = (*w).label; e->y = other_index; e->cost = (*w).cost[other_index];
		min_span_tree[inserted_edge_count] = e;
		inserted_edge_count++;
		prim_update_cost(other_index, is_in_set);
		//v_t->print();
		//std::cout << "\n";
	}//end while
	std::cout << "Prim: ";
	for(int i = 0; i < dimension -1; i++)
		std::cout << "(" << min_span_tree[i]->x << ", " << min_span_tree[i]->y << ")";
	std::cout << "\n\n";
	for(edge *i : min_span_tree){ delete i; i = nullptr;}

}

void Min_Span_Tree::prim_update_cost(int vertex_label, bool is_in_set[]){
	for(int i = 0; i < dimension; i++)
		vertices[vertex_label].cost[i] = inf;
	for(int i = 0; i < dimension; i++){
		if(!is_in_set[i]){
			//std::cout << "waiting find process 3\n";
			for(int j = 0; j < dimension; j++){
				if(vertices[i].cost[j] > adj_matrix[i][j] && adj_matrix[i][j] != 0)
					vertices[i].cost[j] = adj_matrix[i][j];
			}
		}
	}
	/*
	for(int i = 0; i < dimension; i++){
		if(i == vertex_label){
			for(int j = 0; j < dimension; j++){
				vertices[i].cost[j] = inf;
			}
		}
		else{
			for(int j = 0; j < dimension; j++){
				if(!is_in_set[j])
					continue;
				else{//vertex i not in the set, vertex j in the set
					if(vertices[i].cost[j] > adj_matrix[i][j])
						vertices[i].cost[j] = adj_matrix[i][j];
				}
			}
		}
	}
	*/
}
