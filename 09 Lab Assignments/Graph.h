#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <ostream>

using namespace std;
template <class T>
class Graph
{
private:

    set <T> v;//templated set used to store vertices
    multimap <unsigned,unsigned> e;//multimap used to store edges
    // bool idGraph;
    string name;

public:
    Graph();
    Graph(string Gname); 
    void add(T u, T v);
    multimap <unsigned,unsigned> getEdges();
    set <T> getVertices();
    //friend bool operator<<(ostream& os, Graph G );

};


#endif