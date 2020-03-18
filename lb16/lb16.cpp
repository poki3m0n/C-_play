#include <iostream>
#include <cstdio>


using namespace std;
 
 
int main()
{
 
    int a, b;
 
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