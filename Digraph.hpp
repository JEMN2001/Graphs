/*
*Created by Juan Murcia dnd Samuel Perez
*Last update: 24/04/19
*/
#ifndef _Digraph_hpp_
#define _Digraph_hpp_
#include<vector>

template<typename datatype>
class Digraph {
private:
  struct edge {
    std::size_t weight;
    node * link;
  };
  struct node {
    vector<edge> edges;
    datatype data;
  };
  vector<node> nodes;
public:
  Digraph();
  ~Digraph();
  Digraph(Digraph<datatype> & rhs);
  Digraph(vector<vector<int>> & A_matrix);
  bool empty() const;
  std::size_t order() const;
  std::size_t size() const;
  std::size_t max_grade() const;
  std::size_t min_grade() const;
  vector<vector<int>> A_matrix() const;
  void clear();
};

#include "Digraph.cpp"
#endif //_Digraph_hpp_
