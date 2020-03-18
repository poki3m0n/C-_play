#include <iostream>
#include<stack>
#include <string>

using namespace std;

int main()
{ 
	string word;
	stack<char> my_Stack;

	while(cin>>word)
	{
		for(unsigned i=0;i<=word.size();i++)
		{
			if(word[i]=='a')
			{ 
				if (!my_Stack.empty() && my_Stack.top() == 'b')
					my_Stack.pop();
				else
					my_Stack.push(word[i]);
			} 
			else if (word[i]=='b')
			{
				if (!my_Stack.empty() && my_Stack.top() == 'a')
					my_Stack.pop();
				else
					my_Stack.push(word[i]);
			}
			
		}
		if (my_Stack.empty())
			cout<<"\""<<word <<"\"" << " accepted"<<endl;
		else
			cout<<"\""<<word <<"\"" << " REJECTED"<<endl;

		while(!my_Stack.empty())
		{
			my_Stack.pop();
		}
    }
}
