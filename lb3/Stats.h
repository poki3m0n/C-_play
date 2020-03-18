//
//  stats.hpp
//  
//
//  Created by Kritika Rana on 9/9/19.
//

#ifndef Stats_h
#define Stats_h


class Stats
{
private:
    // DATA MEMBERS /////////////////////////////////////////////////////////
    unsigned count;    // number of data elements processed so far
    int      sum;      // sum of all data elements processed so far
    int      minimum;  // minimum of all data elements processed so far
    int      maximum;  // maximum of all data elements processed so far
    
public:
    // MEMBER FUNCTIONS /////////////////////////////////////////////////////
    
    // CONSTRUCTOR(S) ---------------------------------------------------
    Stats();
    
    // SET MEMBER FUNCTIONS or MUTATORS ---------------------------------
    void update( int newData );
    
    // GET MEMBER FUNCTIONS or ACCESSORS --------------------------------
    unsigned getCount();
    int getSum();
    int getMinimum();
    int getMaximum();
    float getAverage();
};
#endif