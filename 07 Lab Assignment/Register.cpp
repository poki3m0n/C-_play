
  
   #include "Register.h"
  
    // Creates an undefined event
    Register::Register( )
    {

    }
    
    // Determines the time of the event
    unsigned Register::getTime() const
    {
        return trans_Time;
    }

    unsigned Register::getTransactionNO() const
    {
        return trans_No;
    }
    // unsigned getAvailQ() const
    // {
    //     return queueAvail;
    // }

    // unsigned setAvailQ() 
    // {

    // }

    bool Register::getAvail() const
    {
        return tell_avil;
    }

    bool Register::setAvail()
    {
        tell_avil = !tell_avil;
        return tell_avil;
    }

    void Register::updateRegister(unsigned time)
    {
        trans_No++;
        trans_Time += time;
    }
    
    				 