#include <iostream>
#include <queue>
#include <fstream> 
#include <math.h>
#include <string>
#include <vector>
#include <sstream>  
#include <iomanip>          
#include "Event.h"
#include "Teller.h"

using namespace std;

vector<string> split( const string& s , char delimiter )
{
	vector<string> tokens; // vector of tokens
	string token; // a single token
	istringstream tokenStream(s); // an input string stream

	// Tokenize s by grabbing individual tokens
	while( getline( tokenStream , token , delimiter ) )
	tokens.push_back(token); // add found token

	return tokens;
}
// Checks whether the teller is available or not and if it is it returns which teller is available.
int availability(vector<Teller> a)
{
    for(int i=0;i<a.size();i++)
    {
        if(a[i].getAvail())
        {
            return i;
        }
        
    }
    return -1;
            
}
// Proccesses the arrival with the arrival event the priority queue and bank queue and multiple tellers
void processArrival(Event arrivalEvent,priority_queue<Event, vector<Event>, greater<Event> >& eventListPQueue,queue<Event>& bankQueue,int currentTime,vector<Teller>& Tellers)
{
    eventListPQueue.pop();
    int departureTime;
    int avail_value=availability(Tellers);
    
    if(bankQueue.empty() && (avail_value!=-1))
    {   Tellers[avail_value].setAvail();//sets the teller availability
        departureTime = currentTime + arrivalEvent.getDuration();// calculate departure time
        Event newDepartureEvent(Event::departure,departureTime, avail_value);//creating new event departures
        eventListPQueue.push( newDepartureEvent );
        Tellers[avail_value].updateTeller(arrivalEvent.getDuration());// updating tellers
    } else bankQueue.push( arrivalEvent );
    
}


// Proccesses the departure with the arrival event the priority queue and bank queue and multiple tellers
void processDeparture(Event departureEvent,priority_queue<Event, vector<Event>, greater<Event> >&eventListPQueue, queue<Event>& bankQueue, int currentTime, vector<Teller>& Tellers)
{
    eventListPQueue.pop();
    int departureTime;
    Tellers[departureEvent.getDuration()].setAvail();
    int avail_value=availability(Tellers);
    
    if( !bankQueue.empty() )
    {
        Event customer = bankQueue.front();
        bankQueue.pop();
        
        departureTime = currentTime + customer.getDuration();
        Event newDepartureEvent(Event::departure,departureTime, avail_value);
        Tellers[avail_value].setAvail();//setting tellers that is available
        eventListPQueue.push( newDepartureEvent );
        Tellers[avail_value].updateTeller(departureEvent.getDuration());//updating tellers
    }
        
}

// Performs the simulation.
int main(int argc, char *argv[])
{
    // Create an empty queue bankQueue to represent the bank line
    // Create an empty priority queue eventListPQueue for the event list

    queue<Event> bankQueue;
    priority_queue <Event, vector<Event>, greater<Event> > eventListPQueue;
    int _transactionTime, _arrivalTime;
    vector<string> tmp;
    queue<int> arrival;
    vector<int> departTime;
    vector<int> arrivaltime;
    bool tellerAvailable = true;
    int sum=0;
	ifstream inFile;
	inFile.open(argv[1]);
    string data;
    string input;
    char delimiter=' ';
    double transTime;
    vector<Teller> Tellers;
    int blah=stoi(argv[2]);

    for(int i=0;i<blah;i++)
    {
        Teller abc;
        Tellers.push_back(abc);
    }
   
    int currentTime;

    while(inFile)
    {
        while (getline(inFile,data))
        {
            
            tmp =split(data,delimiter);
            Event newArrivalEvent =   Event(Event::arrival, stoi(tmp[0]),stoi(tmp[1]));
            eventListPQueue.push( newArrivalEvent ); 
			
        }
    }
    cout<<"<<< BEGIN SIMULATION ("<<blah <<" tellers) >>>"<<endl;
    while (!eventListPQueue.empty())
    {
        Event newEvent = eventListPQueue.top();
        currentTime = newEvent.getTime();

        if(newEvent.getType() == Event::arrival)
        {
            cout<<"Teller"<<setw(3) <<" processing   arrival event at time:"<<setw(5)<< newEvent.getTime()<<setw(5)<<newEvent.getDuration()<<endl;
            processArrival(newEvent, eventListPQueue, bankQueue,currentTime, Tellers);
        }
        else{
            cout<<"Teller "<< 1 <<" processing departure event at time:"<<setw(5)<< newEvent.getTime()<<endl;
            processDeparture(newEvent, eventListPQueue, bankQueue, currentTime, Tellers );
        }
    }
   


    cout<<"<<< END SIMULATION >>>"<<endl;
    cout<<endl;                                                          
    cout<<">>> SIMULATION STATISTICS"<<endl;
    cout<<endl;
    cout<<setw(12)<<"Teller number:"<<endl;
    cout<<setw(3)<<"Transactions processed:"<<endl;
    cout<<"Average transaction time:" <<endl;
    cout<<endl;
    cout<<setw(9)<<"Maximum wait line length:"<<endl;
    cout<<setw(9)<<"Average wait line length:"<<endl;
    cout<<setw(16)<<"Average wait time:";
}



