#include "Graph.h"
#include "lab25.h"
// To allow comparison via second of pair in a map

struct Compare {
bool value;
Compare(bool val) : value(val) {}
};
bool operator==(const pair<string,bool>&p, const Compare& c) {
return c.value == p.second;
}
bool operator==(const Compare& c, const pair<string,bool>&p) {
return c.value == p.second;
}

// Solution to UVA Online Judge Problem #10199: Tourist Guide (modified)

int main()
{
unsigned mapCount=0; // number of city maps read
unsigned R; // number of routes between cities in a map
string src, dst; // source and destination cities

cin >> R;
while( R>0 ) // route information available
{
mapCount++;
string name="City map #"+('0'+mapCount);
Graph< string > cityMap( name , false ); // undirected graph

// Read in each route/edge
for( unsigned i=0 ; i<R ; i++ )
{
cin >> src >> dst;
cityMap.add( src , dst );
}

// Display the city map
// cout << cityMap << endl;

// Find the cameras (articulation points) and report results
map<string,bool> isArticulationPoint=findCameras( cityMap );
cout << "City map #" << mapCount << ": "
<< count( isArticulationPoint.begin() ,
isArticulationPoint.end() ,
Compare(true) )
<< " camera(s) found" << endl;
set<string> location=cityMap.getVertices();
for( auto loc: location )
if( isArticulationPoint[loc] )
cout << " " << loc << endl;
cout << endl;

// Read number of routes for next city map
cin >> R;
}

return 0;
}