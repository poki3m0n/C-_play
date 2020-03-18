#include <queue> 
#include <iostream> 
#include <fstream> 
#include <functional> 
#include <vector> 

using namespace std;

int main()
{
	int arrivalTime, waitTime;

	queue arrival;
	vector<int> arrivalT;

	while (cin >> arrivalTime >> waitTime) //read from file until there are no more times
		{
			arrival.push(arrivalTime); //push arrivalTime into a queue

			arrivalT.push_back(arrivalTime);  //vector of arrivalTime's used for wait time calculation

			newArrivalEvent.setArrival(arrivalTime); //Set event arrival time
			newArrivalEvent.setTime(waitTime); //Set event time (representing wait time)

			eventPriorityQueue.push(newArrivalEvent); //Add newArrivalEvent into eventPriorityQueue

		}
}