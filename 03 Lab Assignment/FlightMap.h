#ifndef MAP_INTERFACE_
#define MAP_INTERFACE_
#include <string>
#include <vector>
#include "MapInterface.h"
#include"Node.h"
using namespace std;

typedef pair<string, bool > Tm;
class FlightMap : public MapInterface
{
private:
	vector<Tm> city;
	
public:
	Tm term;
	
	virtual void read( string cityFileName , string flightFileName );
	virtual bool cityServed(string aCity) const;
    virtual void display() const;
    virtual void displayAllCities() const;
    virtual void displayAdjacentCities(string aCity) const;
    virtual void markVisited( string aCity );
    virtual void unvisitAll();
    virtual bool isVisited( string aCity ) const;
    virtual bool insertAdjacent( string aCity , string adjCity );
    virtual string getNextCity( string fromCity ) const;
    virtual bool isPath( string originCity , string destinationCity );
};

#include"FlightMap.cpp"
#endif