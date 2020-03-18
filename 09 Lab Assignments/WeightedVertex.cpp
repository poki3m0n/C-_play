//vertice name?? weight //aceess
#include "WeightedVertex.h"

    WeightedVertex::WeightedVertex()
    {

    }

    unsigned WeightedVertex::getIndex() const
    {
        return Id;
    }

    unsigned WeightedVertex::getWeight() const
    {
        return IdWeight;
    }
   void  WeightedVertex::updateWeight(unsigned newId, unsigned newIdWeight) const
    {
        Id = newId;
        IdWeight=newIdWeight;
        
    }