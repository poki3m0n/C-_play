// Contacts.h
 #include <string>
    using namespace std;
    
#ifndef CONTACT_H_
#define CONTACT_H_

class Contact
{

  public:
  
   
  
    // Creates an undefined event
    Contact( );
    Contact(string Fname, string Lname, unsigned Bmonth, unsigned Bday, unsigned Byear);
    
    
    // Determines the time of the event
    string getFname() const;

    string getLname() const;
  
    unsigned getBday() const;

    unsigned getBmonth() const;
    
    unsigned getByear() const;

    //void updateContacts(string Fname, string Lname, unsigned Bmonth, unsigned Bday, unsigned Byear);

    //friend bool operator =( const Contact& lhs , const Contact& rhs );


    
    				 
  private:
    
    unsigned Bday;
    unsigned Bmonth;
    unsigned Byear;
    string Fname;
    string Lname;
    
};

#endif