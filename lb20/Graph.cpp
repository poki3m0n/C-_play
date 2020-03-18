#include "Graph.h"
int main()
{
Graph G;

// Add edges to graph G
unsigned u,v;
while( cin >> u >> v )
addEdge( G , u , v );

// Display graph G
cout << G << endl;

// Display strongly connected components of G
cout << "Here are the strongly connected components:" << endl;
 printSCCs( G );

return 0;
}