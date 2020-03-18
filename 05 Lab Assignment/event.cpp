
#include "Event.h"
using namespace std;
    Event::Event( ){}
    Event::Event( eventType type , unsigned time , unsigned duration )
    {
        eType=type;
        eTime=time;
        eDuration=duration;
    }
    Event::Event( const Event& otherEvent )
    {
        eType=otherEvent.getType();
        eTime=otherEvent.getTime();
        eDuration=otherEvent.getDuration();
    }
    
    enum Event :: eventType Event::getType() const
    {
        return eType;
    }
    
    unsigned Event::getTime() const
    {
        return eTime;
    }
    
    unsigned Event::getDuration() const
    {
        return eDuration;
    }
    
     bool operator<( const Event& lhs , const Event& rhs )
    {
        
            return lhs.eTime<rhs.eTime;
    }
     bool operator>( const Event& lhs , const Event& rhs )
    {
        if (lhs.eTime=rhs.eTime)
        {
            if (lhs.eType!=rhs.eType)
            {
                if (lhs.eType==Event::departure)
                {
                    return true;
                } else false;   
            }
        }
        else
            return lhs.eTime>rhs.eTime;
    }
    				   
   