   #include "Contact.h"
   
    Contact::Contact()
    {

    }
     Contact::Contact(string newFname, string newLname, unsigned newBmonth, unsigned newBday, unsigned newByear)
    {
        Fname= newFname;
        Lname= newLname;
        Bday= newBday;
        Bmonth= newBmonth;
        Byear= newByear;

    }

    string Contact::getFname() const
    {
        return Fname;
    }

    string Contact::getLname() const
    {
        return Lname;
    }
  
    unsigned Contact::getBday() const
    {
        return Bday;
    }

    unsigned Contact::getBmonth() const
    {
        return Bmonth;
    }
    
    unsigned Contact::getByear() const
    {
        return Byear;
    }
    

    // void Contact::updateContacts(string newFname, string newLname, unsigned newBmonth, unsigned newBday, unsigned newByear)
    // {
    //     Fname= newFname;
    //     Lname= newLname;
    //     Bday= newBday;
    //     Bmonth= newBmonth;
    //     Byear= newByear;

    // }
    
    //  bool operator =( const Contact& lhs , const Contact& rhs );
