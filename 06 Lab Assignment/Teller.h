// Teller.h

#ifndef TELLER_H_
#define TELLER_H_

class Teller
{

  public:
  
   
  
    // Creates an undefined event
    Teller( );
    
    // Determines the time of the event
    unsigned getTime() const;

    unsigned getTransactionNO() const;

    bool getAvail() const;

    bool setAvail();

    void updateTeller(unsigned time);
    
    				 
  private:
    
    bool tell_avil=true;
    unsigned trans_No;
    unsigned trans_Time;
    
};

#endif