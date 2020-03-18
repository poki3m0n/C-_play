#include <iostream>
#include <string>
using namespace std;

#include "Graph.h" // user-defined template class
#include "lab24.h" // implementation of showDegrees()

int main()
{
Graph< unsigned > G1( "G1" , true ), // directed graph
G2( "G2" ); // undirected graph
unsigned E,u,v;

cin >> E; // number of edges in G1
for( unsigned i=0 ; i<E ; i++ )
{
cin >> u >> v;
G1.add( u , v );
}

cin >> E; // number of edges in G2
for( unsigned i=0 ; i<E ; i++ )
{
cin >> u >> v;
G2.add( u , v );
}

// Display graphs G1 and G2
cout << G1 << endl;
showDegrees( G1 );
cout << G2 << endl;
showDegrees( G2 );

return 0;
}