#include <iostream>
#include "FlightMap.h"
#include "split.cpp"
#include <stack>
#include <fstream>
#include <utility>

using namespace std;

string cities[30];
bool visited[MAX_CITIES];
int numCities;
list<string> mylist ;


    string removeSpecials( string str )
    {
   	    int i=0,len=str.length();
   	    while(i<len) // Check every character
   	    {
        char c=str[i];
        if( !(((c>='0')&&(c<='9')) || ((c>='A')&&(c<='Z')) || ((c>='a')&&(c<='z')) || (c==' ') || (c=='-')) ) 
            {
            str.erase(i,1); // Delete "bad" character
            --len;          // and adjust length
        }
        i++;
    }
    return str;
}
void FlightMap::markVisited(string City);
{   
    unsigned i;
    do
    {
        if(City==Tm[i].first)
            Tm[i].second = true;
        i++
    } while (i<Tm.size());
    
}
  //  typedef <string, string> PAIR1 ; 
    pair <string , string> PAIR1;

void read( string cityFileName , string flightFileName )
{
    char delimiter = ',';

    vector<string> originalPlace;
    vector<string> destinationPlace;
    vector<string> city;


    vector<string>  listofcities;

    // pair<string, string> p1;
    string set1;
    string set2;
    vector<string> flightF;
    vector<string>cityF;
    vector<string> baseCity;

ifstream placef("cityFile.txt");

   
    do
    {   
        while(getline(cityFileName, set1)){
        for(unsigned i=0;i<30;i++)
        {
            cities[i]=removeSpecials(set1);
        }
        }
        
    } while (placef.is_open());

ifstream flightf("flightFile.txt");

    do
    {
        while(getline(flightFileName,set2)){
        place= split(set2, delimiter)
        PAIR1 = make_pair(place[0],place[1])
        mylist.push(PAIR1);
        }
    } while (flightf.is_open());
    
}
	

string FlightMap:: getNextCity(string city) const
{   
    bool flag=false;
    for (iterator it=mylist.begin(); it!=mylist.end(); ++it)
    {
        if(mylist[it].first==city)
        flag=true;
        return mylist[it].second;
    }
    if(flag==false)
    return "null";
    
}
bool FlightMap::isPath(string originCity, string destinationCity)
{
   bool success;
   stack aStack;
   unvisitAll(); // Clear marks on all cities
                 // Push origin city onto aStack and mark it as visited
   aStack.push(originCity);
   markVisited(originCity);
   
   string topCity = aStack.peek();
   while (!aStack.isEmpty() && (topCity != destinationCity))
   {
      // The stack contains a directed path from the origin city
      // at the bottom of the stack to the city at the top of
      // the stack
      
      // Find an unvisited city adjacent to the city on the
      // top of the stack
      string nextCity = getNextCity(topCity);
      
      if (nextCity == "null")
         aStack.pop(); // No city found; backtrack
      else // Visit city
      {
         aStack.push(nextCity);
         markVisited(nextCity);
      } // end if
      
      if (!aStack.isEmpty())
         topCity = aStack.peek();
   } // end while
   
   return !aStack.isEmpty();
} // end isPath
bool FlightMap::isVisited(string City) const
{
    int i;
    do
    {
        if(Tm[i].first == City && Tm[i].second == true)
            return true;
        else
            return false;
        i++;
    } while (i<tm.size());
    
}

bool FlightMap::insertAdjacent(string City, string City2){
    return true;
}
/*
    insertAdjacent( city fromcity, city tocity)
    node<city>*newcity= new node<city>(tocity, Hpair[fromcity])
    Hpair[fromcity]=newcity
*/
void FlightMap::splitCities(string, string&, string&);

template<class ItemType>
void FlightMap::unvisitedAll()
{
	for (int cities = 0; cities < Tm.size(); cities++)

		visited[cities].second = false;
}
template<class ItemType>
void FlightMap::markVisited()
{
	markVisited(city, c);
	visited[c] = true;
}
template<class ItemType>
City FlightMap::getNextCity(City)
{
    City getNextCity(city c)
    list<string> first;
    bool found = false;
	city next = NO_CITY;
    while (iterator it=first.begin() != nullptr and !found){
        if (!isVisited(first.begin())))
		{
			next = first.begin();
				found = true;
		}
		ptr = pts->getnext();
    }
    return next;
}

bool FlightMap::isPath(City originCity, City destinationCity)
{
   bool success;
   Stack aStack;
   unvisitAll(); // Clear marks on all cities
                 // Push origin city onto aStack and mark it as visited
   aStack.push(originCity);
   markVisited(originCity);
   
   City topCity = aStack.peek();
   while (!aStack.isEmpty() && (topCity != destinationCity))
   {
      // The stack contains a directed path from the origin city
      // at the bottom of the stack to the city at the top of
      // the stack
      
      // Find an unvisited city adjacent to the city on the
      // top of the stack
      City nextCity = getNextCity(topCity, nextCity);
      
      if (nextCity == null)
         aStack.pop(); // No city found; backtrack
      else // Visit city
      {
         aStack.push(nextCity);
         markVisited(nextCity);
      } // end if
      
      if (!aStack.isEmpty())
         topCity = aStack.peek();
   } // end while
   
   return !aStack.isEmpty();
} // end isPath


