#include <iostream>
#include <tuple>
using namespace std;

int main()
{
//     tuple<int,int> temp;
//     int a=b=1;
//     while(cin>>data)
//     {
//         temp.push_back(make_tuple(intOne,intTwo));
//     }

//     make_tuple(1,1);
    //int lnum=0,lden=1,rnum=1,rden=0,midnum,midden,a,b;
    // bool flag=0;
    // if(cin>>data)
    // {
    //     cin>>a;
    //     flag=1;
    // }
    // else
    // {
    //     cin>>b;
    //     flag=0;
    // }
    cin>>a>>b;

    while (lnum+rnum != a && lden+rden != b)
    {
        
        if((lnum+rnum)/(float)(rden+lden) < a/(float)b)
        {
            cout<<" l ";
            
            
        }
        if(((lnum+rnum)/(float)(rden+lden)) > (a/(float)b))
        {
            cout<<" r ";
            rnum+=lnum;
            rden+=lden;
        }
    }
    
    return 0;

}