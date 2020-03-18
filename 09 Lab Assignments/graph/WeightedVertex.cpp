//vertice name?? weight //aceess
#include "WeightedVertex.h"
#include<bits/stdc++.h> 
    // default constructor for weighted vertex
    WeightedVertex::WeightedVertex(unsigned id)
    {
        Id = id;
        if(id == 0) {
            IdWeight = 0;
        } else {
            IdWeight = INT_MAX;
        }
    }
    //function to return the ID 
    unsigned WeightedVertex::getIndex() const
    {
        return Id;
    }
    // function to return the weight of the vertex
    unsigned WeightedVertex::getWeight() const
    {
        return IdWeight;
    }
    // update function to update the ID and weight of vertex
    void  WeightedVertex::updateWeight(unsigned newId, unsigned newIdWeight) const
    {
        Id = newId;
        IdWeight=newIdWeight;
        
    }