// Register.h

#ifndef REGISTER_H_
#define REGISTER_H_

class Register
{

  public:
  
   
  
    // Creates an undefined event
    Register( );
    
    // Determines the time of the event
    unsigned getTime() const;

    unsigned getTransactionNO() const;

    bool getAvail() const;

    // unsigned getAvailQ() const;

    // unsigned setAvailQ() const;

    bool setAvail();

    void updateRegister(unsigned time);
    
    				 
  private:
    
    bool tell_avil=true;
    unsigned trans_No;
    unsigned trans_Time;
    unsigned queueAvail;
    
};

#endif