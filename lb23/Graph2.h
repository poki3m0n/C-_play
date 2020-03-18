#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;
typedef struct Graph {
    set<unsigned> V;
    multimap<unsigned, unsigned> E;
} Graph;
void addEdge(struct Graph &Gh, unsigned &u, unsigned &v) {
    Gh.V.insert(u);
    Gh.V.insert(v);
    Gh.E.insert(pair<unsigned, unsigned>(u, v));
    Gh.E.insert(pair<unsigned, unsigned>(v, u));
}
void DFS(unsigned vertex, unsigned p, Graph G, vector<string> &visited, unsigned &c, vector<unsigned> &parent, vector<unsigned> &mark) {
    if(visited[vertex] == "Black")
        return;
    if(visited[vertex] =="Gray") {
        c++;
        unsigned current = p;
        while(current!=vertex) {
            mark[current] = c;
            current = parent[current];
        }
        mark[vertex] = c;
        return;
    }
    parent[vertex] = p;
    visited[vertex] = "Gray";
    for(auto q=G.E.begin();q!=G.E.end();++q){
        unsigned x = 0;
        if(parent[vertex] == (*q).second)
            x = 1;

        if(q->first == vertex && x!=1)
            DFS((*q).second,(*q).first,G,visited,c,parent,mark);
    }
    visited[vertex] = "Black";
}
void displayCycles(Graph G) {
    auto StartVertex = G.V.begin();
    vector<string> visited;
    visited.resize(30);
    vector<unsigned> parent;
    parent.resize(30);
    vector<unsigned> mark;
    mark.resize(30);
    unsigned c = 0;
    for(auto q=G.V.begin(); q!=G.V.end(); ++q)
        visited[*q] = "White";
    DFS((*StartVertex),0,G,visited,c,parent,mark);
    if(c == 0)
        cout<<"No cycles detected.";
    else
        cout<<c<<" cycles detected."<<endl;
    unsigned a = 1;
    while(a<=c) {
        cout<<"Cycle Number "<<a<<": ";
        vector<int> TT;
        for(unsigned i=0;i<mark.size();i++) {
            if(mark[i] == a)
                TT.push_back(i);
        }
        for(unsigned j=0;j<TT.size();j++)
            cout<<TT[j]<<" ";
        cout<<endl;
        TT.clear();
        a++;
    }
    cout<<endl;
}
ostream & operator << (ostream &ot, struct Graph G) {
    vector<pair<unsigned, unsigned> > GG;
    for(auto val:G.E)
        GG.push_back(make_pair(val.first, val.second));
    sort(GG.begin(), GG.end());
    ot<<"Graph has "<<G.V.size()<<" vertices and "<<G.E.size()<<" edges."<<endl;
    ot<<"  V={";
    for(auto p=G.V.begin(); p!=G.V.end(); ++p) {
        ot<<*p;
        auto z=p; z++;
        if(z!=G.V.end())
            ot<<",";
    }
    ot<<"}"<<endl<<"  E={";
    for(auto q=GG.begin(); q!=GG.end(); ++q) {
        ot<<"("<<(*q).first<<","<<(*q).second<<")";
        auto z=q; z++;
        if(z!=GG.end())
            ot<<",";
    }
    ot<<"}";
    return ot;
}
