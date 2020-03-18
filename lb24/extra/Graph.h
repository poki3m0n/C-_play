#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <ostream>
#include "Graph.h"


using namespace std;
template <class T>
class Graph
{
private:
    set <T> v;
    multimap <unsigned,unsigned> e;
    string name;

public:
    bool idGraph = false;
    Graph();
    Graph(string Gname); 
    Graph(string Gname, bool id);
    unsigned getOutDegree(unsigned a);
    unsigned getInDegree(unsigned a);
    void add(T u, T v);
    set<T> getVertices();
    template<class K>
    friend ostream& operator<<(ostream& os,const Graph<K> G );

};

#include "Graph.cpp"
#endif