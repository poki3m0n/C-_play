#include <iostream>
#include <queue>
using namespace std;


int main()
{
  // queue<int> heapsize;
  priority_queue<int> maxheap;
  priority_queue <int, vector<int>, greater<int> > minheap;
  int data;
  // unsigned count=0;
  while (cin>>data)
  {
    // heapsize.push(data);
    maxheap.push(data);
    minheap.push(data);
    // count++;
  }
  // for(unsigned i;i<heapsize.size();i++) 
  while (minheap.empty()== false )
  { 
    cout<< " "<<minheap.top() ; 
    minheap.pop(); 
  } 
  cout<<endl;
  // for(unsigned i;i<heapsize.size();i++)
  while (maxheap.empty()== false)
  { 
    cout<< " " << maxheap.top(); 
    maxheap.pop(); 
  }
  cout<<endl;
}