#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
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
Graph operator + (Graph G1, Graph G2) {
    Graph G3; 
    for(auto p=G1.V.begin(); p!=G1.V.end(); ++p) {    
        G3.V.insert(*p);
    }   
    for(auto p=G2.V.begin(); p!=G2.V.end(); ++p) {
        G3.V.insert(*p);
    }   
    for(auto q=G1.E.begin(); q!=G1.E.end(); ++q) {
        G3.E.insert(pair<unsigned, unsigned>((*q).first, (*q).second));
    }   
    for(auto q=G2.E.begin(); q!=G2.E.end(); ++q) {
        int count=0;
        for(auto r=G3.E.find((*q).first);r!=G3.E.end();r++) {
            if(r->first == (*q).first && r->second == (*q).second)
                count++;
        }
        if(count == 0)
            G3.E.insert(pair<unsigned, unsigned>((*q).first, (*q).second));
    }   
    return G3; 
}
Graph operator - (Graph G1, Graph G2) {
    Graph G3; 
    for(auto p=G1.V.begin(); p!=G1.V.end(); ++p)
        G3.V.insert(*p);
    
    for(auto q=G1.E.begin(); q!=G1.E.end(); ++q)
        G3.E.insert(pair<unsigned, unsigned>((*q).first, (*q).second));
    
    // Declare a temporary set to store the difference values
    set<unsigned> temp;
    for(auto p=G2.V.begin(); p!=G2.V.end(); ++p) {
        for(auto q=G3.V.begin();q!=G3.V.end(); ++q) {
            if ((*p)==(*q)) {
                temp.insert(*p);
                G3.V.erase(*p);
            }
        }
    }
    // Erase the edges if it has the values from the temporary set.
    for(auto q=temp.begin(); q!=temp.end(); ++q) {
        for(auto r=G3.E.begin(); r!=G3.E.end(); ++r) {
            if((*r).first == *q || (*r).second == *q)
                G3.E.erase(r);
        }
    }
    // Erase the edges from the final graph, if it has the edges from G2
    for(auto q=G2.E.begin(); q!=G2.E.end(); ++q) {
        for(auto r=G3.E.begin(); r!=G3.E.end(); ++r) {
            if((*q).first == (*r).first && (*q).second == (*r).second)
                G3.E.erase(r);
        }
    }
    return G3;
}
ostream & operator << (ostream &ot, struct Graph G) {
    vector<pair<unsigned, unsigned>> GG;
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
