#include<iostream>
#include "Graph.hpp"
using namespace std;

void print_vec(vector<size_t> & v);

int main() {
	Graph G("matrix");
	G.print_matrix();
	vector<size_t> path = find_path(G);
	print_vec(path);
	G.print_matrix();
}

void print_vec(vector<size_t> & v) {
	cout << '[';
	for (size_t i = 0; i < v.size(); ++i) {
		if (i < v.size()-1) 
			cout << v.at(i) << ", ";
		else 
			cout << v.at(i) << ']';
	}
}