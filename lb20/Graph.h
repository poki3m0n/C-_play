#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <ostream>

using namespace std;
struct Graph
{
    set<unsigned> v;
    multimap<unsigned,unsigned> e;
    multimap<unsigned,unsigned> v2;

};

void DFSUtil(unsigned u,struct Graph &G,bool  visited[]) ;
Graph getTranspose(Graph& G);
void DFS(struct Graph &G, int a, bool  visited[]);




void fillOrder(int v, bool visited[], stack<int> &Stack) 
{ 
    Graph g;
    // Mark the current node as visited and print it 
    visited[v] = true; 
  
    // Recur for all the vertices adjacent to this vertex 
    
    for (auto it=g.e.begin(); it!=g.e.end(); ++it)
        
        if(v==it->first){
            if(visited[it->second]==false)
            fillOrder(it->second, visited, Stack);
        }
             
  
    // All vertices reachable from v are processed by now, push v  
    Stack.push(v); 
}

void printSCCs(Graph& G) 
{ 
    stack<int> Stack; 
  
    // Mark all the vertices as not visited (For first DFS) 
    bool *visited = new bool[G.v.size()]; 
    for(set<unsigned>::iterator it=G.v.begin(); it!=G.v.end(); ++it)  
        visited[*it] = false; 
  
    // Fill vertices in stack according to their finishing times 
    for(set<unsigned>::iterator it=G.v.begin(); it!=G.v.end(); ++it)  
        if(visited[*it] == false) 
            fillOrder(*it, visited, Stack); 
  
    // Create a reversed graph 
    getTranspose(G); 
  
    // Mark all the vertices as not visited (For second DFS) 
    for(set<unsigned>::iterator it=G.v.begin(); it!=G.v.end(); ++it) 
        visited[*it] = false; 
  
    // Now process all vertices in order defined by Stack 
    while (Stack.empty() == false) 
    { 
        // Pop a vertex from stack 
        int v = Stack.top(); 
        Stack.pop(); 
  
        // Print Strongly connected component of the popped vertex 
        if (visited[v] == false) 
        {   cout<<"  SSC "<<" = ";
            DFSUtil(v,G, visited); 
            cout << endl; 
        } 
    } 
}

Graph getTranspose(Graph& G) 
{   
   
        // Recur for all the vertices adjacent to this vertex 
        
      for (multimap<unsigned,unsigned>::iterator it=G.e.begin(); it!=G.e.end(); ++it)
        {   
            G.v2.insert(make_pair(it->second,it->first));
        } 

    return G; 
}



// A utility function to do DFS of graph 
// recursively from a given vertex u. 
void DFSUtil(unsigned u,struct Graph &G,bool  visited[]) 
{ 
    visited[u] = true; 
    cout << u << " "; 
    for (auto i=G.e.begin(); i!=G.e.end(); ++i) 
        if((*i).first==u)
        {
            if (visited[(*i).second]==false) 
                DFSUtil((*i).second, G,  visited); 
        }
} 
  
// This function does DFSUtil() for all  
// unvisited vertices. 
void DFS(struct Graph &G, int a, bool  visited[]) 
{ 
  
    for (int u=0; u!=a; u++) 
        if (visited[u] == false) 
            DFSUtil(u, G, visited); 
} 

bool connected (struct Graph &G) 
{
   vector<bool> visited(G.v.size(),false);
    //DFS(G,G.v.size(), visited);
    for (unsigned i=0;i<visited.size();i++) 
    {

        if ((visited[i]==false || G.e.size()==G.e.size())) 
        {
            return true;

        }
        return true;
    }
}

void addEdge(Graph &G, unsigned u, unsigned v)
{
    G.v.insert(u);
    G.v.insert(v);

    G.e.insert(make_pair(u,v));

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