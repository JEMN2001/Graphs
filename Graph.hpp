/*
*Created by Juan Murcia dnd Samuel Perez
*Last update: 11/05/19
*/

#ifndef _Graph_hpp_
#define _Graph_hpp_
#include<iostream>
#include<vector>
#include<stack>
#include<unordered_set>
#include<string>
#include<fstream>

/*
*Graph class
*/
class Graph {
  private:
    /*
    *Adjacency matrix of the graph
    */
    std::vector<std::vector<std::size_t>> matrix;
    /*
    *Function that determines if a vertex has no color given a coloration
    *c_nodes: a list with the colors, where the i-th element is the color of the i-th node
    *return: true if a node has no color, false if not
    */
    bool uncolored_vertex(std::vector<std::size_t> c_nodes);
    /*
    *Function that determines if a node has a neighbor with a given color
    *node: node to be checked
    *color: the color to be checked
    *coloration: a list with the colors, where the i-th element is the color of the i-th node
    *return: true if a neighbor of node has the color color, false if not
    */
    bool colored_neighbor(std::size_t node, std::size_t color, std::vector<std::size_t> coloration);
    /*
    *Function that determines if there is an uv-path in the graph
    *u,v: the nodes
    *choices and prev are used for recursion proposes
    *return: true if there is an uv-path, false if not
    */
    bool uv_path(std::size_t u, std::size_t v, std::unordered_set<std::size_t> choices = std::unordered_set<std::size_t>(),std::stack<std::size_t> prev = std::stack<std::size_t>());
  public:
    /*
    *void constructor for the Graph class
    *Creates a new Graph with no vertices or edges
    */
    Graph();
    /*
    *Destroyer of tha class
    *Eliminates a Graph
    */
    ~Graph();
    /*
    *Copy constructor
    *Creates a new Graph, identical to the rhs Graph
    *rhs: Graph that will be copied
    */
    Graph(const Graph & rhs);
    /*
    *matrix constructor
    *Creates a new Graph with an specific adjcency matrix
    *A_matrix: Adjacency matrix for the graph
    */
    Graph(std::vector<std::vector<std::size_t>> & A_matrix);
    /*
    *file constructor
    *Creates a new Graph with a adjacency matrix contained in a txt file
    *the elements of the same row must be separated by commas ','
    *the different arrows must be separated by dots '.'
    *filename: the name of the .txt file
    */
    Graph(std::string filename);
    /*
    *Function that calculated the grado of a node
    *node: the node
    *return: the grade of node
    */
    std::size_t grade(std::size_t node) const;
    /*
    *Function that determines if a graph has no nodes
    *return: true if the graph has no nodes, false if not
    */
    bool empty() const;
    /*
    *Function that gives the number of nodes
    *return: the number of nodes in the graph
    */
    std::size_t order() const;
    /*
    *Function that gives the number of edges
    *return: the number of edges in the graph
    */
    std::size_t size() const;
    /*
    *Function that gives the maximum grade of the graph
    *return: the maximum grade of the graph
    */
    std::size_t max_grade() const;
    /*
    *Function that gives the minimum grade of the graph
    *return: the minimum grade of the graph
    */
    std::size_t min_grade() const;
    /*
    *Function that removes an specific node and all the adjacent edges to that node
    *node: node that will be removed
    *return: true if the node was removed, false if the node wasn't in the graph
    */
    bool remove_node(std::size_t node);
    /*
    *Function that removes an specific edge from the graph
    *u, v: the ends of the edge
    *return: true if the edge was removed, false if there wasn't an edge between u and v;
    */
    bool remove_edge(std::size_t u, std::size_t v);
    /*
    *Method than inserts a new node to the graph
    */
    void add_node();
    /*
    *Function that inserts a new edge to the graph
    *u, v: the ends of the new edge
    *return: true if the edge was added, false if u or v doesn't belong to G
    */
    bool add_edge(std::size_t u, std::size_t v);
    /*
    *Method that clears the Graph
    */
    void clear();
    /*
    *Method that displays the adjacency matrix of the graph
    */
    void print_matrix() const;
    /*
    *Function that determines if there is an eulerian path in he graph
    *G: graph
    *return: an empty vector ih the graph doesn't have an eulerian path
    *        a vector with the eulerian path
    */
    friend std::vector<std::size_t> find_path(Graph & G);
    /*
    *Function that gives a proper coloring for the nodes
    *G: graph
    *return: a list of colors, where the i-th element is the color of the i-th node
    */
    friend std::vector<std::size_t> color_graph(Graph & G);
    /*
    *Function that returns an expansion tree from the graph G using the breadth search algorithm
    *G: graph
    *return: expansion tree of G
    */
    friend Graph breadth_search(Graph & G);
    /*
    *Function that returns an expansion tree from the graph G using the depth search algorithm
    *G: Graph
    *return: expansion tree of G
    */
    friend Graph depth_search(Graph & G);
};

#endif //_Graph_hpp_
