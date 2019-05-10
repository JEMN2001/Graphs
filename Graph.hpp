/*
*Created by Juan Murcia dnd Samuel Perez
*Last update: 24/04/19
*/

#ifndef _Graph_hpp_
#define _Graph_hpp_
#include<iostream>
#include<vector>

class Graph {
  private:
    std::size_t calc_grade(std::size_t node) const;
    std::vector<std::vector<int>> matrix;
  public:
    Graph();
    ~Graph();
    Graph(const Graph & rhs);
    Graph(std::vector<std::vector<int>> & A_matrix);
    bool empty() const;
    std::size_t order() const;
    std::size_t size() const;
    std::size_t max_grade() const;
    std::size_t min_grade() const;
    void clear();
};

#endif //_Graph_hpp_
