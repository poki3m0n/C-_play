   #include "Graph.h"
   #include <set>
   template <class T>
    Graph<T>::Graph()
    {

    }
    template <class T>
    Graph<T>::Graph(string Gname)
    {
        name = Gname;
    }
    template <class T>
    void Graph<T>::add(T u, T v)
    {
        v.insert(u);
        v.insert(v);
        e.insert(make_pair(v,u));
        e.insert(make_pair(u,v));
    }
    template <class T>
    set <T> Graph<T>::getVertices()
    {
        return v;
    }

    // template <class T>
    // ostream& operator<<(ostream& os, Graph G)
    // {
    //     os <<"Graph has "<<G.v.size() << " vertices and " << G.e.size() << " edges."<<endl;
        
    //     os <<"  V={";
    //     for (set<unsigned>::iterator it=G.v.begin(); it!=G.v.end(); ++it)
    //     {
    //         if(it!=G.v.begin())
    //             os<<",";
    //         os << *it;
    //     }
    //     os <<"}" << endl;
    //     os <<"  E={";
    //     for (std::multimap<unsigned,unsigned>::iterator it=G.e.begin(); it!=G.e.end(); ++it)
    //     {
    //         if(it!=G.e.begin())
    //             os<<",";
    //         os <<"("<< (*it).first <<","<< (*it).second<<")";
    //     }
    //     os <<"}";
    //     return os;
        
    // }
   

 