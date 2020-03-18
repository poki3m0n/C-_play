#include <iostream>
#include <queue>

using namespace std;

  int minimum(queue < int >blah)
{	
	int min=blah.front();
	blah.pop();
	while(!blah.empty())
	{
		if (min<blah.front())
			{
				blah.pop();
			}
		else
			{

				min= blah.front();
				blah.pop();
			}
	}
	return min;
}
int main()
{	queue<int> blah;
int count=0;
	int data;
	while(cin>>data)
	{
		blah.push(data);
		count++;
	}
	
	cout<<count<<" "<<minimum(blah)<<endl;

	
}