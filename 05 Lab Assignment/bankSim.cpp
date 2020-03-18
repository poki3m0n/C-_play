#include <queue> 
#include <iostream> 
#include <fstream> 
#include <functional> 
#include <vector> 
#include "event.h"#include <iostream>
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




bankSimulation();
processArrival(Event event1, PriorityQueue & pq, Queue & line);
processDeparture(Event event1, PriorityQueue & pq, Queue & line);

using namespace std;


int main()
{
	banksimulation();
}

void Simulation::bankSimulation()
{
	//priority queue of Events (int arrival,int time)
	PriorityQueue eventPriorityQueue; 

	//queue for bank line
	Queue bankLine;

	//queue for arrival times obtained from the file. Used for determining whether a time is an arrival or departure
	Queue arrival;

	//Event object 
	Event newArrivalEvent;
        int arrivalTime= 0;
	int departureTime = 0;
	int waitTime = 0;
	int currentTime = 0;
	int customer = 0;
    vector<int> departTime;
	vector<int> arrivalT;
    queue arrival;
	vector<int> arrivalT;
	priority_queue<int> newArrivalEvent;
    bool tellerAvailable = false;

	int custSize = 0, sum = 0; //custSize tracks total number of customers
							   //sum used to calculate total wait time

	tellerAvailable = true; //Teller is available for a customer

	//Read from file
	std::string fileName = "input.txt";
	std::ifstream inFile;
	inFile.open(fileName);

	if (!inFile) //Error check that file open properly
	{
		std::cout << "Error: Could not open file.\n";
	}
	else
	{
		std::cout << "Simulatin Begins: \n\n";
		while (inFile >> arrivalTime >> waitTime) //read from file until there are no more times
		{
			arrival.push(arrivalTime); //push arrivalTime into a queue

			arrivalT.push_back(arrivalTime);  //vector of arrivalTime's used for wait time calculation

			newArrivalEvent.setArrival(arrivalTime); //Set event arrival time
			newArrivalEvent.setTime(waitTime); //Set event time (representing wait time)

			eventPriorityQueue.push(newArrivalEvent); //Add newArrivalEvent into eventPriorityQueue

		}
	}

	departTime.push_back(0); //Used to align depart times with arrival times for total wait time calculation

	while (!eventPriorityQueue.empty()) //Process arrival and departure events while the eventPriorityQueue is not empty
	{
		Event newEvent = eventPriorityQueue.top(); //Event object = first event in eventPriorityQueue

		currentTime = newEvent.getArrival(); //current time is either an arrival time or calculated departure time

		if (arrival.front() == currentTime) //Use arrival queue to determine if the current time matches an arrival time. If yes, process an arrival event
		{
			std::cout << "Process arrival event at time: " << currentTime << std::endl; //display arrival time
			processArrival(newEvent, eventPriorityQueue, bankLine); //Call processArrival function
			if (arrival.size() != 1) //Keeps .pop() from going out of range of the arrival queue
				arrival.pop();

			custSize++; //increment custSize to track total number of customers
		}
		else //If not an arrival time, then process a departure event
		{
			departTime.push_back(currentTime); //Track departure times
			std::cout << "Process departure event at time: " << currentTime << std::endl; //Display departure time 
			processDeparture(newEvent, eventPriorityQueue, bankLine); //Call processDeparture function
		}

	}

	
	for (int i = 0; i < custSize - 1; i++) //Loop 0 -> 10-1 to calculate total wait time
	{
		int waitT = departTime[i] - arrivalT[i]; //Wait time = departure time - arrival time

		if (waitT > 0) //Only add values > 0 to wait time sum. Values < 0 means that there was no wait involved
		{
			sum = sum + waitT;
		}
	}

	float avg = (float)sum / custSize; //Calculate average as a float and cast operand to float to get the answer of 5.6

	//Display results
	std::cout << "\nFinal Statistics: \n\n";
	std::cout << "\tNumber of transactions processed: " << custSize << std::endl;
	std::cout << "\tAverage wait time: " << avg << std::endl;
	std::cout << "\nSimulation Ends\n";
	inFile.close();
}

//processArrival Function
void Simulation::processArrival(Event event1, PriorityQueue & pq, Queue & line)
{
		pq.pop(); //Remove top element of priority queue

	if (!line.empty()) //only calls line.front() if line as any elements
		customer = line.front();
	else //customer = 1
		customer = 1;

	if (line.empty() && tellerAvailable) //Line and teller are open, process arrival event
	{
		departureTime = currentTime + event1.getTime(); //Use arrival and wait time to determine when the customer leaves

		Event departure; //Create temp departure Event
		departure.setArrival(departureTime); //Set new event arrival to current departure time
		pq.push(departure); //push departure time into priority queue

		tellerAvailable = false; //teller is no longer available
	}
	else
		line.push(customer); //add customer to the line queue
}

//processDeparture Function
void Simulation::processDeparture(Event event1, PriorityQueue & pq, Queue & line)
{

	Event newE; //Event object


	if (pq.size() > 2) //if size is greater than 2 use top of priority queue 
	{
		pq.pop();
		newE = pq.top();
	}
	else //use event1 for newE for departureTime calculation
	{
		pq.pop();
		newE = event1;
	}
	

	if (!line.empty()) //if line is not empty
	{
		customer = line.front(); //current customer is at the front of the line
		line.pop(); // remove first person in line
		departureTime = currentTime + newE.getTime(); //calculate departure time to be currunt time - wait time

		Event departure; //Event object
		departure.setArrival(departureTime); //Set arrival time of departure
		departure.setTime(5); //Set time (a.k.a wait time)

		pq.push(departure); //Add new departure time to priority queue


	}
	else
		tellerAvailable = true; //teller is now available
}
