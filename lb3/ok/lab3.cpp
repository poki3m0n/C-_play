//
//  lab3.cpp
//  
//
//  Created by Kritika Rana on 9/9/19.
//
#include<iostream>
#include<string>
#include "Stats.h"
using namespace std;
int main() {
    Stats statistics;
    
    int data;
    while( cin >> data ) {
        statistics.update( data );
    }
    
    // Display all the basic statistics in the following order:
    // count, minimum, maximum, sum, and average.
    
    // Insert code here
    cout<<"count   = "<<statistics.getCount()<<endl;
    cout<<"minimum = "<<statistics.getMinimum()<<endl;
    cout<<"maximum = "<<statistics.getMaximum()<<endl;
    cout<<"sum     = "<<statistics.getSum()<<endl;
    cout<<"average = "<<statistics.getAverage()<<endl;

    return 0;
}
