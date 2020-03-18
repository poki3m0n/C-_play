#ifndef GRAPH_H
#define GRAPH_H
#include <set>
#include <map>
#include <ostream>
#include <iostream>


using namespace std;
struct Graph
{
    set<unsigned> v;
    multimap<unsigned,unsigned> e;

};
void addEdge(Graph &G, unsigned u, unsigned v)
{
    G.v.insert(u);
    G.v.insert(v);
    G.e.insert(make_pair(u,v));
    G.e.insert(make_pair(v,u));

}

ostream& operator<<(ostream& os, Graph G)
{
    os <<"Graph has "<<G.v.size() << " vertices and " << G.e.size() << " edges."<<endl;
    
    os <<"  V={";
    for (set<unsigned>::iterator it=G.v.begin(); it!=G.v.end(); ++it)
    {
        if(it!=G.v.begin())
            os<<",";
        os << *it;
    }
    os <<"}" << endl;
    os <<"  E={";
    for (std::multimap<unsigned,unsigned>::iterator it=G.e.begin(); it!=G.e.end(); ++it)
    {
        if(it!=G.e.begin())
            os<<",";
        os <<"("<< (*it).first <<","<< (*it).second<<")";
    }
    os <<"}";
    return os;
    
}

#endif