#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <ostream>

using namespace std;
// const int N = 100000; 

// // variables to be used 
// // in both functions 
// vector<int> graph[N]; 
// vector<int> cycles[N]; 

struct Graph
{
    set<unsigned> v;
    multimap<unsigned,unsigned> e;
    multimap<unsigned,unsigned> v2;

};


void addEdge(Graph &G, unsigned u, unsigned v)
{
    G.v.insert(u);
    G.v.insert(v);
    G.e.insert(make_pair(v,u));
    G.e.insert(make_pair(u,v));

}

// Function to mark the vertex with 
// different colors for different cycles 
void dfs_cycle(unsigned node, unsigned u,struct Graph &G,vector<unsigned> &visited, unsigned &counter, vector<unsigned> &previst, vector<unsigned> &marked) 
{ 
  if(visited[node] == 2)
        return;
    if(visited[node] == 1) {
        counter++;
        unsigned current = u;
        while(current!=node) {
            marked[current] = counter;
            current = previst[current];
        }
        marked[node] = counter;
        return;
    }
    previst[node] = u;
    visited[node] = 1;
    for(multimap<unsigned,unsigned>::iterator it=G.e.begin();it!=G.e.end();++it){
        unsigned x = 0;
        if(previst[node] == it->second)
            x = 1;
            if(it->first == node && x!=1)
            dfs_cycle((*it).second,(*it).first,G,visited,counter,previst,marked);
    }
    visited[node] = 2;
} 

void displayCycles(Graph G) {
    set<unsigned>::iterator initialize = G.v.begin();
    vector<unsigned> visited;
    vector<unsigned> add;
    vector<unsigned> previsit;
    vector<unsigned> marked;
    unsigned count = 0;
    unsigned number = 1;
    for(set<unsigned>::iterator it=G.v.begin(); it!=G.v.end(); it++)
       {
           visited[*it] = 0;
       }
    dfs_cycle((*initialize),0,G,visited,count,previsit,marked);
    if(count == 0)
    {
        cout<<"No cycles detected.";
    }
    else
    {
        cout<<count<<" cycles detected."<<endl;
    }
    
    while(number<=count) 
    {
        cout<<"Cycle Number "<<number<<": ";
        vector<unsigned> tem;
        for(unsigned it=0;it<marked.size();it++) 
        {
            if(marked[it] == number)
                tem.push_back(it);
        }
        for(unsigned it=0;it<tem.size();it++)
            cout<<tem[it]<<" ";
        cout<<endl;
        tem.clear();
        number++;
    }
    cout<<endl;
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