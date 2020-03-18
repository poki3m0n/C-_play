#include"Graph2.h"
int main()
{
Graph G;
unsigned E,u,v;

cin >> E; // number of edges in G
for( unsigned i=0 ; i<E ; i++ )
{
cin >> u >> v;
addEdge( G , u , v );
}

// Display graph G
cout << G << endl;

displayCycles( G );

return 0;
}