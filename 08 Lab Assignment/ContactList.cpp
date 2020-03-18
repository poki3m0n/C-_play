#include"Contact.h"
#include "ContactList.h"
using namespace std;
    bool ContactList ::   isEmpty() const 
    {
        if(index_vec.empty())
            return true;
        else
            return false;
        
    }

    /** Determines the number of entries (records) in the database2.
        @return The number of entries/records in the database2. */
    unsigned ContactList ::   getSize() const 
    {
        return index_vec.size();
    }

    /** Adds a new record into the database2.
        @param newData  The new record to add to the database2.
        @post  The database2 contains the new record.
        @return  True if the addition is successful, or false if not. */
    bool ContactList :: add( const Contact& newData ) 
    {
        database2.push_back(newData);
        index_vec.insert({newData.getLname(),count});
        count++;
        return true;
        
    }

    /** Removes the record with the given key from this database2.
	    Returns false if duplicate records matching the key exist.
		Default format for aKey is the value of the key (based on index);
        otherwise, two values may be provided, separated by commas,
        to identify a particular record that matches the extended key
        (done if there are duplicates).
        @param aKey  The key of the record to remove from the database2.
        @return  True if the removal is successful, or false if not. */
    bool ContactList ::   remove( const string& aKey ) 
    {
        multimap<string,unsigned>::iterator it=index_vec.find(aKey);
        if (it != index_vec.end())
        {
            database2[it->second]=database2[count-1];
            count--;
            multimap<string,unsigned>::iterator it2=index_vec.find(database2[count-1].getLname());
            it2->second = it->second;
            index_vec.erase(it);
            return true;
        }
        else false;
        
    }

    /** Removes all record(s) with the given key from this database2.
        @param aKey  The key of the record(s) to remove from the database2.
        @return  True if the removal is successful, or false if not. */
    bool ContactList :: removeAll( const string& aKey ) 
    {
        // multimap<string,unsigned>::iterator it=index_vec.find(akey);
        int x= index_vec.count(aKey);
        if (x!=0)
        {
            // int x= index_vec.count(akey);
            for(int i=0;i<=x;i++)
            {
                multimap<string,unsigned>::iterator it=index_vec.find(aKey);
                // index_vec.erase(akey);
                // count--;
                database2[it->second]=database2[count-1];
                count--;
                multimap<string,unsigned>::iterator it2=index_vec.find(database2[count-1].getLname());
                it2->second = it->second;
                index_vec.erase(it);
                
            }
            return true;
            
        }
        else return false;
        

    }

    /** Removes all records from this database2. */
    void ContactList ::   clear() 
    {
        index_vec.clear();
        database2.clear();
        count=0;
    }

    /** Gets an entry (or entries) with the matching key from this database2.
        @post  The desired entry/entries has been returned in a set, and the
            database2 is unchanged. If no such entry was found, an exception
            is thrown.
        @param aKey  The key of the record to locate from the database2.
        @return  The set containing the entry (or entries) in the database2
            that matches the given search key.
        @throw  NotFoundException if the given entry is not in the database2. */
     set<Contact> ContactList ::getEntry( const string& aKey ) const throw(NotFoundException)
    {    
        
        set<Contact> temp;
        int x= index_vec.count(aKey);
        if (x!=0)
        {
            
            //pair <multimap<string,unsigned>::iterator,multimap<string,unsigned>::iterator> ret;
            //ret = index_vec.equal_range(aKey);  
            //std::cout << ch << " =>";
            //for (std::multimap<string,unsigned>::iterator it=ret.first; it!=ret.second; ++it)
            //std::cout << ' ' << it->second;
            for(auto it=index_vec.begin(); it!=index_vec.end(); ++it){
            if(it->first==aKey)
            {
                for(unsigned x=0;x<index_vec.size();x++)
                {
                if((it->second)==x){
                // temp.insert(database2[it->second]);
                }
                }
            }
                
        
        }
            return temp;
        
        
    }
    }
    /** Tests if an entry matching the given key occurs in this database2.
        @post  The database2 is unchanged.
        @param aKey  The search key of the entry to find.
        @return  True if the entry occurs in the database2, or false if not. */
     bool ContactList ::contains( const string& aKey ) const 
    {
        int x= index_vec.count(aKey);
        if (x!=0)
        {
            return true;
        }
        else return false;
        

    }
    //
    void ContactList :: display()
    {
        for (auto it=index_vec.begin(); it!=index_vec.end(); ++it)
            //c.database2(it->second);
            for(unsigned i=0;i<database2.size();i++)
            {
                if((it->second)==i)
                    cout<<c.getFname()<<" "<<c.getLname()<<","<<" "<<c.getBmonth()<<"/"<<c.getBday()<<"/"<<c.getByear()<<endl;
            }
            
    }

    vector<Contact> ContactList :: write()
    {

        return database2;
    }

   
