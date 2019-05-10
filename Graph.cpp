#ifndef _Graph_cpp_
#define _Graf_cpp_
#include "Graph.hpp"

std::size_t Graph::calc_grade(std::size_t node) const{
  std::size_t sum = 0;
  for (std::size_t i = 0; i < this->matrix.size(); ++i) {
    sum += this->matrix[node][i];
  }
  return sum;
}
Graph::Graph() {
  this->matrix = std::vector<std::vector<int>>();
}

Graph::~Graph() {
    this->matrix.clear();
}

Graph::Graph(const Graph & rhs) {
  this->matrix = rhs.matrix;
}

Graph::Graph(std::vector<std::vector<int>> & A_matrix) {
  this->matrix = A_matrix;
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
    sum += this->calc_grade(i);
  }
  return sum/2;
}

std::size_t Graph::max_grade() const {
  std::size_t grade = 0, tmp;
  for(std::size_t i = 0; i < this->matrix.size(); ++i) {
    tmp = calc_grade(i);
    if (tmp > grade)
      grade = tmp;
  }
  return grade;
}

std::size_t Graph::min_grade() const {
  std::size_t grade = calc_grade(0),tmp;
  for (std::size_t i = 1; i < this->matrix.size(); ++i) {
    tmp = calc_grade(i);
    if (tmp < grade)
      grade = tmp;
  }
  return grade;
}

void Graph::clear() {
  this->matrix.clear();
}

#endif //_Graph_cpp_
