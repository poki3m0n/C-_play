#include<iostream>

using namespace std;

void display(int n, int b)
{

	if (n>0)
	{
		if(n/b>0){
			display(n/b,b);
		}	
	//n%b;
	//int s;
	//n = n/b;
	//if (rem<0)
		//numbers+=1;
			

		if (n%b > 10){
             cout<<(char)((n%b - 10) + 'A' );
         }

       else{
          cout<<n%b;
       }
        //answer = s + answer;
	//cout<<"x"<<s<<endl;
	//cout<< rem+(base * -1): rem;
   }
}


int main()
{
	int base,total_numbers;
	//if(base>1 && base<=30)
	int i;
	while(cin>>base>>total_numbers)
	{
		int numbers[total_numbers];


		for ( i = 0; i < total_numbers; i++)
		{
			cin>>numbers[i];
		}
		cout<<"Conversion to base-"<<base<<":"<<endl;
		
		for (int j = 0; j < total_numbers; j++)
		{		
			cout<<"  "<<numbers[j]<<":";
			display(numbers[j],base);
			cout<<endl;
		}cout<<endl;
	}	
	return 0;

}