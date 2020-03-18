// WeightedVertix.h
 #include <string>
    using namespace std;
    
#ifndef WEIGHTEDVERTEX_H_
#define WEIGHTEDVERTEX_H_

class WeightedVertex
{

    public:

        WeightedVertex(unsigned id);// default constructor for weighted vertex

        unsigned getIndex() const; //function to return the ID 

        unsigned getWeight() const;// function to return the weight of the vertex

        void updateWeight(unsigned newId, unsigned newIdWeight);// update function to update the ID and weight of vertex
        
        unsigned x,y,dist;
  				 
    private:

        unsigned Id;
        unsigned IdWeight;
        
    
};

#endif