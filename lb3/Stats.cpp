//
//  stats.cpp
//  
//
//  Created by Kritika Rana on 9/9/19.
//

#include "Stats.h"
#include <iostream>

using namespace std;


// CLASS SPECIFICATION

// A class that handles basic statistics on a set of integer data.

Stats::Stats()
{
    count=0;
    sum=minimum=maximum=0;
}

void Stats::update( int newData )
{
    //int a[99];
    // Insert code here
    count++;
    sum+= newData;
     //int minimum=a[0];
     if(count==1)
     {
        maximum=newData;
        minimum=newData;

     }
     if(newData<minimum)
     {
        minimum=newData;
     }
     if (maximum<newData)
     {
         maximum=newData;
     }


   /* for(int i=0;i<99;i++)
    {
        if(a[i]<minimum)
        {
            minimum=a[i];
        }
    }
    int maximum=a[0];
    for(int i=0;i<99;i++)
    {
        if(maximum<a[i])
            maximum=a[i];
    }*/

}

unsigned Stats::getCount()
{
    // Insert code 
    return count;
}

int Stats::getSum()
{
    // Insert code here
    
    return sum;
}

int Stats::getMinimum()
{
    // Insert code here
   
    return minimum;
}

int Stats::getMaximum()
{
    // Insert code here
    return maximum;
}

float Stats::getAverage()
{
    // Insert code here
    float avg=0.0f;
   
    return avg=(double)sum/count;
}
