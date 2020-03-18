#include <iostream>
#include <queue>
#include <stack>
using namespace std;

template<class ItemType>
void show(queue < ItemType >value)
{
    while(!value.empty())
	{
    	cout<<value.front()<<endl;
		value.pop();
	}
	;

}
template<class ItemType>
void reverse(queue< ItemType >&value)
{
	stack<ItemType> rev;
	 while(!value.empty())
	{
    	rev.push(value.front());
		value.pop();
	}
	while(!rev.empty())
	{
		value.push(rev.top());
		rev.pop();
	}

}

//   int minimum(queue < int >blah)
// {	
// 	int min=blah.front();
// 	blah.pop();
// 	while(!blah.empty())
// 	{
// 		if (min<blah.front())
// 			{
// 				blah.pop();
// 			}
// 		else
// 			{

// 				min= blah.front();
// 				blah.pop();
// 			}
// 	}
// 	return min;
// }
int main()
{	queue<int> values;
	// stack<int> sval;
// int count=0;
	int data;
	while(cin>>data)
	{
		values.push(data);
		// count++;
		// sval.push(data);
	}
	show(values);
	reverse(values);
	cout<<endl;
	show(values);

	
}