#include <iostream>
#include <string>
#include <fstream>
#include "FlightMap.h"

using namespace std;

int main()
{
	FlightMap game;
	string data;
	string data1;
	string data2;
	vector <string> place;
	bool setter;
	bool setter1=false;
	bool setter2=false;
   	cin>>data;
	cin>>data1;
	cin>>data2;
	read(data,data1);
	ifstream request(data2)
	do
    {
        getline(request,set2)
        place= split(set2, ',');
		for(int i=0;i<sizeof(cities);i++)
		{
			if (place[0]==cities[i])
			{
				setter1=true;
			}
			
			if (place[1]==cities[i])
			{
				setter2=true;
			}
			
		}
		if(setter1==false)
		{
			cout<<"Hpair does not serve"<<place[0];
		}
		else if(setter2==false)
		{
			cout<<"Hpair does not serve"<<place[1];
		}
		else
		{
			setter=game.isPath(removeSpecials(place[0]),removeSpecials(place[1]));
			if(setter==true)
			{
				cout<<"HPair flies from "<<place[0]<<"to "<<place[1];
			}
			else
			{
				cout<<"Hpair does not fly from"<<place[0]<<"to "<<place[1];
			}
		}
		
	 } while (request.is_open());
	
	
}