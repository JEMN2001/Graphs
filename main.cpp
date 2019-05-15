#include<iostream>
#include "Graph.hpp"
using namespace std;

void print_vec(vector<size_t> & v);

int main() {
	Graph G("matrix"), T;
	G.print_matrix();
	vector<size_t> path = find_path(G), coloration = color_graph(G);
	print_vec(path);
	print_vec(coloration);
	T = breadth_search(G);
	T.print_matrix();
	T = depth_search(G);
	T.print_matrix();
	size_t length = shortest_uv_path(G,0,4);
	cout << length << endl;
}

void print_vec(vector<size_t> & v) {
	cout << '[';
	for (size_t i = 0; i < v.size(); ++i) {
		if (i < v.size()-1)
			cout << v.at(i) << ", ";
		else
			cout << v.at(i) << ']';
	}
	cout << endl;
}
