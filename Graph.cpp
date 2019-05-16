#ifndef _Graph_cpp_
#define _Graf_cpp_
#include "Graph.hpp"

std::size_t Graph::grade(std::size_t node) const{
  std::size_t sum = 0;
  for (std::size_t i = 0; i < this->matrix.size(); ++i) {
    sum += this->matrix[node][i];
  }
  return sum;
}
Graph::Graph() {
  this->matrix = std::vector<std::vector<std::size_t>>();
}

Graph::~Graph() {
    this->matrix.clear();
}

Graph::Graph(const Graph & rhs) {
  this->matrix = rhs.matrix;
}

Graph::Graph(std::vector<std::vector<std::size_t>> & A_matrix) {
  this->matrix = A_matrix;
}

Graph::Graph(std::string filename) {
	this->matrix = std::vector<std::vector<std::size_t>>();
	std::ifstream file;
	file.open(filename+".txt");
	if (!file) {
		std::cerr << "Couldn't open the file " << filename << std::endl;
	}
	else {
		std::vector<std::size_t> v;
		std::string tmp = "";
		char x;
		while (file >> x) {
			switch (x) {
				case '0':
				tmp.push_back(x); break;
				case '1':
				tmp.push_back(x); break;
				case '2':
				tmp.push_back(x); break;
				case '3':
				tmp.push_back(x); break;
				case '4':
				tmp.push_back(x); break;
				case '5':
				tmp.push_back(x); break;
				case '6':
				tmp.push_back(x); break;
				case '7':
				tmp.push_back(x); break;
				case '8':
				tmp.push_back(x); break;
				case '9':
				tmp.push_back(x); break;
				case ',':
				v.push_back((size_t) std::stoi(tmp)); tmp = ""; break;
				case '.':
				v.push_back((size_t) std::stoi(tmp)); this->matrix.push_back(v);
				tmp = ""; v.clear(); break;
			}
		}
		file.close();
	}
}

bool Graph::empty() const {
  return this->matrix.size() == 0;
}

std::size_t Graph::order() const {
  return this->matrix.size();
}

std::size_t Graph::size() const {
  std::size_t sum = 0;
  for(std::size_t i = 0; i < this->matrix.size(); ++i) {
    sum += this->grade(i);
  }
  return sum/2;
}

std::size_t Graph::max_grade() const {
  std::size_t grade = 0, tmp;
  for(std::size_t i = 0; i < this->matrix.size(); ++i) {
    tmp = this->grade(i);
    if (tmp > grade)
      grade = tmp;
  }
  return grade;
}

std::size_t Graph::min_grade() const {
  std::size_t grade = this->grade(0),tmp;
  for (std::size_t i = 1; i < this->matrix.size(); ++i) {
    tmp = this->grade(i);
    if (tmp < grade)
      grade = tmp;
  }
  return grade;
}

bool Graph::remove_node(std::size_t node) {
	if (this->matrix.size() <= node)
		return false;
	this->matrix.erase(this->matrix.begin()+node);
	for (std::size_t i = 0; i < this->matrix.size(); ++i) {
		(this->matrix.at(i)).erase((this->matrix.at(i)).begin()+node);
	}
	return true;
}

bool Graph::remove_edge(std::size_t u, std::size_t v) {
	if (this->matrix.size() <= u || this->matrix.size() <= v)
		return false;
	if (this->matrix[u][v] == 0)
		return false;
	this->matrix[u][v]--;
	this->matrix[v][u]--;
	return true;
}

void Graph::add_node() {
	for (std::size_t i = 0; i < this->matrix.size(); ++i) {
		(this->matrix.at(i)).push_back(0);
	}
	this->matrix.push_back(std::vector<std::size_t>(this->matrix.size()+1, 0));
}

bool Graph::add_edge(std::size_t u, std::size_t v) {
	if (this->matrix.size() <= u || this->matrix.size() <= v)
		return false;
	this->matrix[u][v]++;
	this->matrix[v][u]++;
	return true;
}

void Graph::clear() {
  this->matrix.clear();
}

void Graph::print_matrix() const {
	std::cout << std::endl;
  char ch;
	for (std::size_t i = 0; i < this->matrix.size(); ++i) {
    std::cout << '|';
		for (std::size_t j = 0; j < this->matrix[i].size(); ++j) {
      ch = ' ';
      if (j == this->order()-1)
        ch = '|';
			std::cout << this->matrix[i][j] << ch;
		}
		std::cout << std::endl;
	}
  std::cout << std::endl;
}

std::vector<std::size_t> find_path(Graph & G) {
	Graph tm = G;
	std::vector<std::size_t> adj, path;
	std::size_t order = tm.order();
	for (std::size_t i = 0; i < order; ++i) {
		adj.push_back(tm.grade(i));
	}
	std::size_t start = 0, odd = 0;
	for (std::size_t i = 0; i < adj.size(); ++i) {
		if (adj.at(i)%2 == 1) {
			odd++;
			start = i;
		}
	}
	if (odd > 2)
		return path;
	std::stack<std::size_t> stk;
	std::size_t cur = start;
	while(!stk.empty() || tm.grade(cur) != 0) {
		if (tm.grade(cur) == 0) {
			path.push_back(cur);
			cur = stk.top();
			stk.pop();
		}
		else {
			for (std::size_t i = 0; i < order; ++i) {
				if (tm.matrix[cur][i] >= 1) {
					stk.push(cur);
					tm.matrix[cur][i]--;
					tm.matrix[i][cur]--;
					cur = i;
					break;
				}
			}
		}
	}
	path.push_back(cur);
	return path;
}

bool Graph::uncolored_vertex(std::vector<std::size_t> c_nodes) const{
	for (std::size_t i = 0; i < c_nodes.size(); ++i) {
		if(c_nodes.at(i) == 0)
			return true;
	}
	return false;
}

bool Graph::colored_neighbor(std::size_t node, std::size_t color, std::vector<std::size_t> coloration) const{
	for (std::size_t i = 0; i < this->matrix.size(); ++i) {
		if (this->matrix[node][i] > 0 && coloration.at(i) == color)
			return true;
	}
	return false;
}

std::vector<std::size_t> color_graph(Graph & G) {
	std::vector<std::size_t> out;
	for (std::size_t i = 0; i < G.matrix.size(); ++i)
		out.push_back(0);
	std::size_t color = 1;
	while(G.uncolored_vertex(out)) {
		for (std::size_t i = 0; i < out.size(); ++i) {
			if (out.at(i) == 0 && !G.colored_neighbor(i,color,out))
				out.at(i) = color;
		}
		color++;
	}
	return out;
}

bool Graph::uv_path(std::size_t u, std::size_t v, std::unordered_set<std::size_t> choices, std::stack<std::size_t> prev) const{
	choices.insert(v);
	for (std::size_t i = 0; i < this->order(); ++i) {
		if (u == i && this->matrix[u][v] > 0)
			return true;
		if(u != i && this->matrix[v][i] > 0 && choices.count(i) == 0) {
			prev.push(v);
			return uv_path(u,i,choices,prev);
		}
	}
	if (prev.size() == 0)
		return false;
	std::size_t tmp = prev.top();
	prev.pop();
	return uv_path(u,tmp,choices,prev);
}

Graph breadth_search(Graph & G) {
	std::size_t order = G.order();
	Graph out;
	for (std::size_t i = 0; i < order; ++i)
		out.add_node();
	for (std::size_t i = 0; i < order; ++i) {
		for (std::size_t j = i; j < order; ++j) {
			if (G.matrix[i][j] > 0 && !out.uv_path(i,j))
				out.add_edge(i,j);
		}
	}
	return out;
}

Graph depth_search(Graph & G) {
    std::size_t order = G.order();
    Graph out;
    for (std::size_t i = 0; i < order; ++i)
      out.add_node();
    for (std::size_t i = 0; i < order; ++i) {
      for (std::size_t j = 0; j < order; ++j) {
        if (G.matrix[i][j] > 0 && !out.uv_path(i,j) && out.matrix[i][j] == 0) {
          out.add_edge(i,j);
          break;
        }
      }
    }
    return out;
}

std::vector<std::size_t> shortest_uv_path(Graph & G, std::size_t u, std::size_t v) {
  std::vector<std::size_t> values,path,out;
  std::set<std::size_t> Tm;
  std::size_t big = 1e7;
  if (u >= G.order() || v >= G.order()) {
    std::cerr << "on of the nodes doesn't belong to the graph" << std::endl;
    return path;
  }
  for (std::size_t i = 0; i < G.order(); ++i) {
    if (i == u)
      values.push_back(0);
    else
      values.push_back(big);
    Tm.emplace(i);
    path.push_back(big);
  }
  std::size_t vertex = 0;
  while(Tm.count(v) > 0) {
    for(auto i = Tm.cbegin(); i != Tm.cend(); ++i) {
    	if(i == Tm.cbegin())
    		vertex = *i;
    	if(values[*i] < values[vertex])
    		vertex = *i;
    }
    Tm.erase(vertex);
    for (std::size_t i = 0; i < G.order(); ++i) {
      if (G.matrix[vertex][i] > 0) {
        if (values[vertex]+1 < values[i]) {
          values[i] = values[vertex]+1;
          path[i] = vertex;
        }
      }
    }
  }
  if (path[v] == big)
  	return out;
  out.push_back(u);
  std::size_t cur = v;
  auto it = out.cbegin();
  while(cur != u) {
  	it = out.cbegin()+1;
  	out.insert(it,cur);
  	cur = path[cur];
  }
  return out;
}

#endif //_Graph_cpp_
