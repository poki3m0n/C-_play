#include<iostream>

using namespace std;

void display(unsigned n, unsigned b)
{
	if (n>0)
	{
		if(n/b>0)
	
	//n%b;
	//int s;
	n = n/b;
	//if (rem<0)
		//numbers+=1;
			display(n,b);
		if (n%b >= 10){
             cout<<(char)( 'A'  + (n%b - 10) );
         }
       else
           cout<<n%b;
        //answer = s + answer;
	//cout<<"x"<<s<<endl;
	//cout<< rem+(base * -1): rem;
   }
}


/*
void display(int N, int b)
{
     if (N == 0)
        return;
     int x = N % b;
     N /= b;
     if (x < 0)
        N += 1; 
     display(N, b);
    // cout<< x < 0 ? x + (b * -1) : x;
     digit = convertFrom % convertTo;

        if (x < 10)
            stringDigit = '0' + x;
        else
            stringDigit = digit - 10 + 'A';

        answer = stringDigit + answer;

        convertFrom /= convertTo;     

     return;
}

*/
int main()
{
	int base=0,total_numbers=0;
	//if(base>1 && base<=30)
    int i;
	cin>>base>>total_numbers;
	
	int numbers[total_numbers];

	for (i = 0; i < total_numbers; i++)
	{
		cin>>numbers[i];
	}
	
		
	for (int j = 0; j < total_numbers; j++)
	{
			display(numbers[i],base);
			cout<<endl;
	}
	return 0;
}