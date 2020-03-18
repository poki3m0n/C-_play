#ifndef GRAPH_H
#define GRAPH_H
#include <set>
#include <map>
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>


using namespace std;
struct Graph
{
    set<unsigned> v;
    multimap<unsigned,unsigned> e;
    friend Graph operator+( Graph G1, Graph G2);

};
void addEdge(Graph &G, unsigned &u, unsigned &v)
{
    G.v.insert(u);
    G.v.insert(v);
    G.e.insert(make_pair(u,v));
    G.e.insert(make_pair(v,u));

}
Graph operator * ( Graph G1, Graph G2)
{
    Graph result;
    for (set<unsigned>::iterator it=G1.v.begin(); it!=G1.v.end(); ++it)
    {
        for (set<unsigned>::iterator it1=G2.v.begin(); it1!=G2.v.end(); ++it1)
        {
            if (*it==*it1)
            {
                result.v.insert(*it);
            }
            
        }
    }
    for (multimap<unsigned,unsigned>::iterator it=G1.e.begin(); it!=G1.e.end(); ++it)
    {
        for (multimap<unsigned,unsigned>::iterator it1=G2.e.begin(); it1!=G2.e.end(); ++it1)
        {
            if (((*it).first==(*it1).first)&&(*it).second==(*it1).second)
            {
                result.e.insert(make_pair((*it).first,(*it1).second));
            }
            
        }
    }
    return result;
}

Graph operator + ( Graph G1, Graph G2)
{
    Graph result;
    for (set<unsigned>::iterator it=G1.v.begin(); it!=G1.v.end(); ++it)
    {
        result.v.insert(*it);
    }
    for (set<unsigned>::iterator it=G2.v.begin(); it!=G2.v.end(); ++it)
    {
        result.v.insert(*it);
    }
    for (multimap<unsigned,unsigned>::iterator it=G1.e.begin(); it!=G1.e.end(); ++it)
    {
        result.e.insert(make_pair((*it).first, (*it).second));
    }
    for (multimap<unsigned,unsigned>::iterator it=G2.e.begin(); it!=G2.e.end(); ++it)
    {
        int x =0;
        for(multimap<unsigned,unsigned>::iterator bt=result.e.find(it->first);bt!=result.e.end();++bt)
        {
            if(bt->first == it->first && bt->second == it->second)
              x++;
        }
        if (x==0)
        {
            result.e.insert(make_pair(it->first, it->second));
        }
    }
    return result;
}

Graph operator - ( Graph G1, Graph G2) {
    Graph result; 
    set<unsigned> t;
    for(set<unsigned>::iterator it=G1.v.begin(); it!=G1.v.end(); ++it)
        result.v.insert(*it);
    
    for(multimap<unsigned,unsigned>::iterator it=G1.e.begin(); it!=G1.e.end(); ++it)
        result.e.insert(make_pair((*it).first, (*it).second));
    
    
    for(set<unsigned>::iterator it=G2.v.begin(); it!=G2.v.end(); ++it) 
    {
        for(set<unsigned>::iterator ti=result.v.begin(); ti!=result.v.end(); ++ti) 
        {
            if ((*it)==(*ti)) 
            {
                t.insert(*it);
                result.v.erase(*it);
            }
        }
    }

    for(set<unsigned>::iterator it=t.begin(); it!=t.end(); ++it) 
    {
        for(multimap<unsigned,unsigned>::iterator ti=result.e.begin(); ti!=result.e.end(); ++ti) 
        {
            if((*ti).first == *it || (*ti).second == *it)
                result.e.erase(ti);
        }
    }
    
    for(multimap<unsigned,unsigned>::iterator it=G2.e.begin(); it!=G2.e.end(); ++it) 
    {
        for(multimap<unsigned,unsigned>::iterator ti=result.e.begin(); ti!=result.e.end(); ++ti)  
        {
            if((*it).first == (*ti).first && (*it).second == (*ti).second)
                result.e.erase(ti);
        }
    }
    return result;
}
ostream& operator<<(ostream& os, Graph G)
{
    vector < pair < unsigned, unsigned> > GG;
    for(auto val:G.e)
        GG.push_back(make_pair(val.first, val.second));
    sort(GG.begin(), GG.end());
    os <<"Graph has "<<G.v.size() << " vertices and " << G.e.size() << " edges."<<endl;
    
    os <<"  V={";
    for (set<unsigned>::iterator it=G.v.begin(); it!=G.v.end(); ++it)
    {
        if(it!=G.v.begin())
            os<<",";
        os << *it;
    }
    os <<"}" << endl;
    os <<"  E={";
    for (std::multimap<unsigned,unsigned>::iterator it=G.e.begin(); it!=G.e.end(); ++it)
    {
        if(it!=G.e.begin())
            os<<",";
        os <<"("<< (*it).first <<","<< (*it).second<<")";
    }
    os <<"}";
    return os;
    
}

#endif