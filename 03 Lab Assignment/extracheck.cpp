#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Route
{
    string   from;
    string   to;
    int       distance;
};

const int Total_routes = 10;

Route routes [ Total_routes ] =
    { { "F", "I", 20 }, { "F", "B", 45 }, { "H", "C", 25 },
      { "B", "E", 50 }, { "I", "E", 60 }, { "F", "C", 60 },
      { "H", "G", 50 }, { "B", "G", 30 },
      { "H", "D", 45 }, { "A", "E", 40 } } ;

int adjacency ( string point , Route routes[] )
{
    int adjacency = 0;
    for ( int c ( 0 ) ; c < Total_routes ; c++ )
    {
        if ( ( routes[c].from.compare(point) == 0 ) || ( routes[c].to.compare(point) == 0 ) )
        {
            adjacency++;
        }
    }
    return adjacency;
}

void find_adjacent_points ( string point , Route routes[] , string adjacent_points[] )
{
    int x = 0;
    for ( int z ( 0 ) ; z < Total_routes ; z++ )
    {
        if ( routes[z].from.compare(point) == 0 )
        {
            adjacent_points[x] = routes[z].to;
            x++;
        }
        if ( routes[z].to.compare(point) == 0 )
        {
            adjacent_points[x] = routes[z].from;
            x++;
        }
    }
}

void find_route( string currpoint , string finishpoint , Route routes[] , string temp_routes[] , int& points_visited )
{
    temp_routes[points_visited] = currpoint;
    points_visited++;
    if (currpoint.compare(finishpoint)==0)
    {
        cout << "route found" << endl;
    }
    else
    {
        string adjacent_points[10];
        for ( int i ( 0 ) ; i < points_visited-1 ; i++ )
        {
            if ( temp_routes[i] == currpoint )
            {
                return;
            }
        }
        find_adjacent_points ( currpoint , routes , adjacent_points );
        for ( int r ( 0 ) ; r < (adjacency(currpoint,routes)) ; r++ )
        {
            int temp_points_visited = points_visited;
            find_route( adjacent_points[r] , finishpoint , routes , temp_routes , points_visited );
            for ( int e ( temp_points_visited ) ; e < points_visited ; e++ )
            {
                temp_routes[e] = " ";
            }
            points_visited = temp_points_visited;
        }
    }
}

void travel ( Route routes[] , string temp_routes[] )
{
    int points_visited ( 0 );
    string startstr, finishstr;
    cout << "Input starting point: ";
    getline(cin,startstr);
    cout << "Input finishing point: ";
    getline(cin,finishstr);
    if ( startstr == finishstr )
    {
        cout << "You're already there!" << endl;
    }
    else
    {
        for ( int g ( 0 ) ; g <= ((adjacency(startstr,routes))-1) ; g++ )
        {
            find_route ( startstr , finishstr , routes , temp_routes , points_visited );
        }
    }
}

bool cont ()
{
    string answ;
    cout << "Try a new route? <Y/N> : ";
    getline(cin,answ);
    cout << endl;
    if ( answ == "Y" )
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main ()
{
    string temp_routes[50];
    while ( cont() )
    {
        travel (routes,temp_routes);
    }
    return 0 ;
}