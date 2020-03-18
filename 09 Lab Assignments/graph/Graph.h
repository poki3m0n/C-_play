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
    set <T> v;
    multimap <unsigned,unsigned> e;
    // bool idGraph;
    string name;

public:
    Graph();
    Graph(string Gname); 
    void add(T u, T v);
    
    set <T> getVertices();
    //friend bool operator<<(ostream& os, Graph G );

};


#endif