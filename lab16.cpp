#include <iostream>
#include <tuple>
using namespace std;

int main()
{
    // tuple<int,int> temp;
    int a,b;
    // while(cin>>data)
    // {
    //     temp.push_back(make_tuple(intOne,intTwo));
    // }

    // make_tuple(1,1);
    // int lnum=0,lden=1,rnum=1,rden=0,midnum,midden,a=3,b=5;
    
   
        
    //     while (lnum+rnum != a && lden+rden != b)
    //     {
    //         if(a==1 && b ==1)
    //         break;
    //         if((lnum+rnum)/(double)(rden+lden) < a/(double)b)
    //         {
    //             cout<<" l ";
    //             lnum=lnum+rnum;
    //             lden=lden+rden;
                
    //         }
    //         if(((lnum+rnum)/(double)(rden+lden)) > (a/(double)b))
    //         {
    //             cout<<" r ";
    //             rnum=rnum+lnum;
    //             rden=rden+lden;
    //         }
    //     }

    while( cin >> a >> b)
    {
       
        if (a == 1 && b == 1) return 0;
        int midnum=1,midden=1,lnum=0,rnum=1,rden=0,lden=1;
        string output ="";
        double value = (double)a/b;
        for(;midnum != a || midden != b;midnum = lnum + lden,midden = rnum + rden)
        {

            if (value > (double)midnum/midden)
                rnum = midden,lnum = midnum,
                output += "r";
            else
                rden = midden,lden = midnum,
                output += "l";
        }
        cout << output << endl;
 
    }
    
    return 0;

}