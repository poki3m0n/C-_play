#include <iostream>
#include <queue>
#include <fstream> 
#include <math.h>
#include <string>
#include <vector>
#include <sstream>  
#include <iomanip>          
#include "Event.h"
#include "Register.h"

using namespace std;

int shortestQ(vector < queue < Event > > a)
{
    int shortest = 0;

    for (int i = 0; i < a.size(); i++)
    {
        if(a[i].size()==0)
        return i;
        else if(a[i].size() < a[shortest].size())
        shortest = i;
    }
   
    return shortest;
}

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
// Checks whether the Register is available or not and if it is it returns which teller is available.
int availability(vector<Register> a)
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
void processArrival(Event arrivalEvent,priority_queue<Event, vector<Event>, greater<Event> >& eventListPQueue,int currentTime,vector<Register>& Registers,  vector< queue < Event > >& sQ)
{
    eventListPQueue.pop();
    int departureTime;
    int avail_value=availability(Registers);
   // int availQvalue=shortestQ(sQ);
   
    if((avail_value!=-1))
    {   Registers[avail_value].setAvail();//sets the Register availability
        departureTime = currentTime + arrivalEvent.getDuration();// calculate departure time
        Event newDepartureEvent(Event::departure,departureTime, avail_value);//creating new event departures
        eventListPQueue.push( newDepartureEvent );
        Registers[avail_value].updateRegister(arrivalEvent.getDuration());// updating Register
        int z = avail_value+1;
        cout<<"Register"<<setw(3)<<avail_value <<" processing   arrival event at time:"<<setw(5)<< arrivalEvent.getTime()<<setw(5)<<arrivalEvent.getDuration()<<endl;

    } else
    { 
        int shortQ=shortestQ(sQ);
        sQ[shortQ].push(arrivalEvent);

    }
    
}


// Proccesses the departure with the arrival event the priority queue and bank queue and multiple tellers
void processDeparture(Event departureEvent,priority_queue<Event, vector<Event>, greater<Event> >&eventListPQueue, int currentTime, vector<Register>& Registers,vector< queue < Event > >& sQ)
{
    eventListPQueue.pop();
    //cout << "1" << endl;
    int departureTime;
    int x= departureEvent.getIndex();
    if(!sQ[x].empty())
    {
     Event customer = sQ[x].front();
        sQ[x].pop();
    
    departureTime = currentTime + customer.getDuration();
    Event newDepartureEvent(Event::departure,departureTime, x);
    Registers[x].setAvail();//setting tellers that is available
    eventListPQueue.push( newDepartureEvent );
    Registers[x].updateRegister(departureEvent.getDuration());//updating tellers
    Registers[x].setAvail();
    int z= x+1;
    cout<<"Register "<< z<<" processing departure event at time:"<<setw(5)<< departureEvent.getTime()<<endl;

    }

    else 
    {
        cout<<"HAHA DO NOTHING";
    }
        
}

// Performs the simulation.
int main(int argc, char *argv[])
{
    // Create an empty queue bankQueue to represent the bank line
    // Create an empty priority queue eventListPQueue for the event list
    if(argc==1) {
        cout<<"Correct usage: eventSim filename count"<<endl;
        cout<<setw(66)<<"where filename is the simulation data filename; and"<<endl;
        cout<<setw(69)<<"  count is the number of registers (1..10) to use."<<endl<<endl;
        return 1;
    }
    vector< queue < Event > > seprateQueue;
    queue<Event> bankQueue;
    priority_queue <Event, vector<Event>, greater<Event> > eventListPQueue;
    int _transactionTime, _arrivalTime;
    vector<string> tmp;
    queue<int> arrival;
    vector<int> departTime;
    vector<int> arrivaltime;
    bool registerAvailable = true;
    int sum=0;
	ifstream inFile;
	inFile.open(argv[1]);
    string data;
    string input;
    char delimiter=' ';
    double transTime;
    vector<Register> Registers;
    int blah=stoi(argv[2]);
    //int queueCount=0;

    for(int i=0;i<blah;i++)
    {
        Register abc;
        queue<Event> abcd;
        Registers.push_back(abc);
        seprateQueue.push_back(abcd);

    }
   
    int currentTime;

    while(inFile)
    {
        while (getline(inFile,data))
        {
            
            tmp =split(data,delimiter);
           // queueCount++;
            Event newArrivalEvent =   Event(Event::arrival, stoi(tmp[0]),stoi(tmp[1]));
            eventListPQueue.push( newArrivalEvent ); 
			
        }
    }
    cout<<"<<< BEGIN SIMULATION ("<<blah <<" Register) >>>"<<endl;
    //Processing the events depending on departure or arrrival event
    while (!eventListPQueue.empty())
    {
        Event newEvent = eventListPQueue.top();
        //get current time
        currentTime = newEvent.getTime();

        if(newEvent.getType() == Event::arrival)
        {
            //cout<<"Register"<<setw(3) <<" processing   arrival event at time:"<<setw(5)<< newEvent.getTime()<<setw(5)<<newEvent.getDuration()<<endl;
            processArrival(newEvent, eventListPQueue,currentTime, Registers, seprateQueue);
        }
        else{
            //cout<<"Register "<< 1 <<" processing departure event at time:"<<setw(5)<< newEvent.getTime()<<endl;
            processDeparture(newEvent, eventListPQueue, currentTime, Registers, seprateQueue );
        }
    }
   


    cout<<"<<< END SIMULATION >>>"<<endl;
    cout<<endl;                                                          
    cout<<">>> SIMULATION STATISTICS"<<endl;
    cout<<endl;
    cout<<setw(12)<<"Register number:";
    for(int i=0;i<atoi(argv[2]);i++)
        cout<<setw(8)<<i+1;
    cout<<setw(3)<<"Transactions processed:"<<endl;
    cout<<"Average transaction time:  ";
    for(int i=0;i<atoi(argv[2]);i++) 
        cout<<setw((i==0)?6:8)<<setprecision(2)<<fixed;
    cout<<endl;
    cout<<setw(9)<<"Maximum wait line length:"<<endl;
    cout<<setw(9)<<"Average wait line length:"<<endl;
    cout<<setw(16)<<"Average wait time:";
}



