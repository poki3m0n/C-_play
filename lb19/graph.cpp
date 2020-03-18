#include "Graph.h"

int main()
{
Graph G;

unsigned u,v;
while( cin >> u >> v )
addEdge(G, u, v);

cout << G << endl;

 cout << "The graph is " << ( connected(G) ? "" : "not " )
 << "connected." << endl;

 return 0;
}