#include <iostream>
#include<set>

using namespace std;

void show(set<int> fset)
{
    set<int>:: iterator it;
    for (it=fset.begin(); it!=fset.end(); ++it)
    {
        cout<<" "<<*it;
    }
    
}

void show_reverse(set<int> rset)
{
    set<int>::reverse_iterator rit;
    for ( rit=rset.rbegin(); rit!=rset.rend(); ++rit)
    {
        cout<<" "<<*rit;
    }
}

int main()
{
    int data;
    set <int> pset;
    while(cin>>data)
        pset.insert(data);
    show(pset);
    cout<<endl;
    show_reverse(pset);
    cout<<endl;
}