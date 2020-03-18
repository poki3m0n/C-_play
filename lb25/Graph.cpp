#include "Graph.h"
#include <iostream>
#include <set>
#include <map>
#include <ostream>

    template< class T>
    Graph<T>::Graph()
        {

        }
    template< class T>
    Graph<T>::Graph(string Gname)
        {

        }
    //  template< class T>
    // Graph<T>::Graph(string Gname, bool id)
    //     {

    //     }

    // template<class T>
    // unsigned Graph<T>::getOutDegree(unsigned a)
    //     {   
            
            
    //         //for (multimap<T,T>::iterator it=G.e.begin(); it!=G.e.end(); ++it)
    //         unsigned x= e.count(a);
    //         return x;
            
    //     }
    // unsigned Graph<T>::getInDegree(unsigned a)
    //     {   
                
    //         map<unsigned, unsigned> m1;

    //         for (auto&& item : G)
    //         {
    //             m1.emplace(item.second, item.first);
    //         }

    //         //for (multimap<T,T>::iterator it=m1.begin(); it!=m1.end(); ++it)
    //         return m1.count(a);
            
    //     }
    template <class T>
    void Graph<T>::add(T u, T v)
        {
            v.insert(u);
            v.insert(v);
            e.insert(make_pair(v,u));
            e.insert(make_pair(u,v));
        }

    template <class T>
    set<T> Graph<T>::getVertices()
        {
            return v;
        }

        template<class T>
    ostream& operator<<(ostream& os, Graph<T> G)
    {
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