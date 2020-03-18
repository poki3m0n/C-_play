#ifndef GRAPH_H
#define GRAPH_H
using namespace std;
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <stack>


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
    Graph(string Gname); 
    Graph(string Gname, bool id);
    unsigned getOutDegree(unsigned a);
    unsigned getInDegree(unsigned a);
    void add(T u, T v);
    set<T> getVertices();
    
    friend ostream& operator<<(ostream& os, Graph<T> G );

};


#endif