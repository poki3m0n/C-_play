// Contacts.h
 #include <string>
    using namespace std;
    
#ifndef WEIGHTEDVERTEX_H_
#define WEIGHTEDVERTEX_H_

class WeightedVertex
{

    public:
  
        WeightedVertex(unsigned id);

        unsigned getIndex() const;

        unsigned getWeight() const;

        void updateWeight(unsigned newIdWeight);
  				 
    private:
    
        unsigned Id;
        unsigned IdWeight;
        
    
};

#endif