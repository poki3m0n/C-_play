
  
   #include "Teller.h"
  
    // Creates an undefined event
    Teller::Teller( )
    {

    }
    
    // Determines the time of the event
    unsigned Teller::getTime() const
    {
        return trans_Time;
    }

    unsigned Teller::getTransactionNO() const
    {
        return trans_No;
    }

    bool Teller::getAvail() const
    {
        return tell_avil;
    }

    bool Teller::setAvail()
    {
        tell_avil = !tell_avil;
        return tell_avil;
    }

    void Teller::updateTeller(unsigned time)
    {
        trans_No++;
        trans_Time += time;
    }
    
    				 