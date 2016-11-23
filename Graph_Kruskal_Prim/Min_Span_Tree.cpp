/*
void Min_Span_Tree::prim(int dimension){
	edge *min_span_tree[dimension -1];
	int inserted_edge_count = 0;
	Set the_set = Set(dimension);

	struct vertex *v = new vertex[dimension];
	int v_inserted = 0;
	//V_t = {1} --start at vertex 1; which means start at 0th node
	v[v_inserted].index = 0; v_inserted++;
	prim_updateQ(v[v_inserted-1].index, dimension);

	while(!pq.isEmpty() && v[dimension-1].index == -1){
		edge *e = pq.pop();
		min_span_tree[inserted_edge_count] = e;
		inserted_edge_count++;
		v[v_inserted].index = e->y; v_inserted++;
		prim_updateQ(v[v_inserted-1].index, dimension);
	}

	for(int i = 0; i < dimension -1; i++)
		std::cout << "(" << min_span_tree[i]->x << ", " << min_span_tree[i]->y << ")";
	std::cout << "\n";
}

void Min_Span_Tree::prim_updateQ(int just_inserted, int dimension){
	for(int j = 0; j < dimension; j++){
		if(adj_matrix[just_inserted][j] != 0){
			edge *e = new edge(); e->x = just_inserted ; e->y = j; e->cost = adj_matrix[just_inserted][j];
			pq.insert(e);
		}
	}//end for
}
*/
