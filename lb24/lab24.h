#include "Graph.h"
#include <iomanip>
#include <set>
using namespace std;
template< class T>
void showDegrees(Graph<T> &G)
{
    set<unsigned> temp = G.getVertices();
    
    if(!G.idGraph)
    {
        cout<<setw(11)<<"Vertex"<<setw(11)<<"inDegree"<<setw(11)<<"outDegree";
        for (auto it=temp.begin(); it!=temp.end(); ++it)
        cout<<setw(11)<<*it<<setw(11)<<G.getInDegree(*it)<<setw(11)<<G.getOutDegree(*it);
    }
    else
    {
        cout<<setw(11)<<"Vertex"<<setw(11);
        for (auto it=temp.begin(); it!=temp.end(); ++it)
        cout<<setw(11)<<*it<<setw(11)<<G.getInDegree(*it);
    }
    
}
    
