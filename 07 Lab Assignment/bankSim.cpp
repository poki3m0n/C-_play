/* CSCI 310-02 Programming Assignment 6
 * @file bankSim.cpp
 * Purpose: Implement the event-driven simulation of a bank
 * @author: Piradeepan Nagarajan
 * version 1.1 11/03/2019
 */
#include <iostream>
#include <vector> // For vector
#include <fstream> // For file input
#include <queue> // For Queue
#include <sstream> // For istringstream
#include <iomanip> // Sets the field width to be used on output operations
#include <string> // For Strings
#include <algorithm>
#include "Event.h" // Header file
#include "Teller.h"
using namespace std;
// Set the teller to true at the initial stage
bool tellerAvailable = true;
// Current time
unsigned currentTime;
vector<int> waitLine;
// Total transaction time
double totalTime;
// Total arrival time
double TAtime;
// Total departure time
double TDtime;
// Total transaction time
double TTtime;
// To get the customers in the normal bank queue - declare an empty queue
queue<Event> bankQueue;
// To get the priority customers in the line - declare an empty priority queue
priority_queue<Event, vector<Event>, greater<vector<Event>::value_type>> eventListPQueue;
// Function to split the strings from the input stream
vector<string> split(const string& s, char delimiter) {
    vector<string> tokens; // vector of tokens
     string token; // a single token
     istringstream tokenStream(s); // an input string stream
     // Tokenize s by grabbing individual tokens
     while(getline(tokenStream, token, delimiter))
         tokens.push_back(token); // add found token
     return tokens;
}
// Processes an arrival event.
void processArrival(Event arrivalEvent, vector<int> &TQ, vector<double> &tAtime, vector<double> &tDtime, vector<double> &tTtime, vector<int> &count) {
// Remove this event from the event list
    eventListPQueue.pop();
    Event customer(arrivalEvent); // customer referenced in arrivalEvent
    TAtime += customer.getTime();
    if(bankQueue.empty()== true && tellerAvailable == true) {
        unsigned departureTime = currentTime + arrivalEvent.getDuration();
        totalTime += arrivalEvent.getDuration();
        for(unsigned i=0;i<TQ.size();i++) {
            if(TQ[i]==0) {
                TQ[i] = departureTime;
                // Calculate the total departure time for each customer
                tDtime[i] += departureTime;
                // Calculate the total transaction time for each customer
                tTtime[i] += arrivalEvent.getDuration();
                tAtime[i] += customer.getTime();
                count[i] += 1;
                // Calculate the total departure time for each customer
                TDtime += departureTime;
                // Calculate the total transaction time for each customer
                TTtime += arrivalEvent.getDuration();
                Event newDepartureEvent(Event::departure, departureTime, 0, i); //a new departure event with departureTime
                eventListPQueue.push(newDepartureEvent);
                cout<<"Teller"<<setw(3)<<i+1<<" processing"<<setw(27)<<" arrival event at time:  "<<setw(3)<<arrivalEvent.getTime()<<setw(5)<<arrivalEvent.getDuration()<<endl;
                break;
            }
        }
        tellerAvailable = false;
        for(unsigned i=0;i<TQ.size();i++) {
            if(TQ[i]==0) {
                tellerAvailable = true;
                break;
            }
        }

    } else
        bankQueue.push(customer);
   if(!bankQueue.empty())
         waitLine.push_back(bankQueue.size()-1);
     else
         waitLine.push_back(0);
}
// Processes a departure event.
void processDeparture(Event arrivalEvent, vector<int> &TQ, vector<double> &tAtime, vector<double> &tDtime, vector<double> &tTtime, vector<int> &count) {
    // Remove this event from the event list
    eventListPQueue.pop();
    cout<<"Teller"<<setw(3)<<arrivalEvent.getTeller()+1<<" processing departure event at time:  "<<setw(3)<<arrivalEvent.getTime()<<endl;
    if(!bankQueue.empty()) {
        // Customer at front of line begins transaction
        Event customer(bankQueue.front());
        bankQueue.pop();
        unsigned departureTime = currentTime + customer.getDuration();
        
        // Calculate the total departure time for each customer
        tDtime[arrivalEvent.getTeller()] += departureTime;
        // Calculate the total transaction time for each customer
        tTtime[arrivalEvent.getTeller()] += customer.getDuration();
        TDtime += departureTime;
        TTtime += customer.getDuration();
        totalTime += customer.getDuration();
        count[arrivalEvent.getTeller()] += 1;
        Event newDepartureEvent(Event::departure, departureTime, 0, arrivalEvent.getTeller()); //a new departure event with departureTime
        eventListPQueue.push(newDepartureEvent);
        cout<<"Teller"<<setw(3)<<arrivalEvent.getTeller()+1<<" processing"<<setw(27)<<" arrival event at time:  "<<setw(3)<<arrivalEvent.getTime()<<setw(5)<<customer.getDuration()<<endl;        
    } else
        tellerAvailable = true;
    TQ[arrivalEvent.getTeller()]=0;
}
int main(int argc, char *argv[]) {
    if(argc==1) {
        cout<<"Correct usage: bankSim filename count"<<endl;
        cout<<setw(66)<<"where filename is the simulation data filename; and"<<endl;
        cout<<setw(67)<<"count is the number of tellers (1..10) to use."<<endl<<endl;
        return 1;
    }
    int eTime, eDuration;
    ifstream EventFile;
    string input, edata;
    vector<string> eInput;
    vector<int> TQ;
    TQ.resize(atoi(argv[2]));
    vector<double> tAtime;
    tAtime.resize(atof(argv[2]));
    vector<double> tDtime;
    tDtime.resize(atof(argv[2]));
    vector<double> tTtime;
    tTtime.resize(atof(argv[2]));
    vector<int> count;
    count.resize(atoi(argv[2]));

    char delimiter = ' ';
    // Open the file and read for processing
    // To calculate the number of transactions
    int c=0;
    EventFile.open(argv[1]);
    // while end of file read all the lines from the file
    while(!EventFile.eof()) {
        // Get the line on eby one
        getline(EventFile,edata);
        // Store all the lines in a vector
        eInput = split(edata, delimiter);
        // Read all the values from the vector
        for(unsigned i=0;i<eInput.size();i++) {
            // Get first arrival time value
            if(i%2==0) {
                eTime = stoi(eInput[i]);
            } else { // Get the time duration
                eDuration = stoi(eInput[i]);
                // Create a new arrival event
                Event newArrivalEvent(Event::arrival, eTime, eDuration);
                // Insert the attival event into the priority queue
                eventListPQueue.push(newArrivalEvent);
                // increment the counter for number of transactions
                c++;
            }
        }
    }
    cout<<"<<< BEGIN SIMULATION ("<<argv[2]<<" tellers) >>>"<<endl;
    // Event loop
    while(!eventListPQueue.empty()) {
        Event newEvent(eventListPQueue.top());
        // Get current Time
        currentTime = newEvent.getTime();
        // Process the new event for new arrival
        if(newEvent.getType() == Event::arrival)
            processArrival(newEvent, TQ, tAtime, tDtime, tTtime, count); // Process the arrival event for the customer
        else
            processDeparture(newEvent, TQ, tAtime, tDtime, tTtime, count); // Process the departure event for the customer
    }
    cout<<"<<< END SIMULATION >>>"<<endl<<endl;
    cout<<">>> SIMULATION STATISTICS"<<endl<<endl;
    cout<<setw(25)<<"Teller number:";
    for(int i=0;i<atoi(argv[2]);i++)
        cout<<setw(8)<<i+1;
    cout<<setw(10)<<"OVERALL";
    cout<<endl<<setw(25)<<"Transactions processed:";
    for(int i=0;i<atoi(argv[2]);i++) 
        cout<<setw(8)<<count[i];
    cout<<setw(10)<<c;
    cout<<endl<<setw(26)<<"Average transaction time:  ";
    for(int i=0;i<atoi(argv[2]);i++) 
        cout<<setw((i==0)?6:8)<<setprecision(2)<<fixed<<(tTtime[i]/count[i]);
    cout<<setw(10)<<setprecision(2)<<fixed<<(totalTime/c);
    cout<<endl<<endl;
    cout<<setw(45)<<"Maximum wait line length:";
    int waitMax = *max_element(waitLine.begin(), waitLine.end());
    cout<<setw(10)<<setprecision(0)<<((waitMax==1)?0:(waitMax));
    cout<<endl<<setw(45)<<"Average wait line length:";
    double WM = 0;
    for(unsigned i=0;i<waitLine.size();i++)
        WM += waitLine[i];
    cout<<setw(10)<<setprecision(2)<<fixed<<((WM==1)?0:(WM/c));
    cout<<endl<<setw(45)<<"Average wait time:";
    cout<<setw(10)<<setprecision(2)<<fixed<<(TDtime-TAtime-TTtime)/c<<endl<<endl;
    return 0;
}
