/**
*  CSCI 310, Lab #1
 *  @file lab1.cpp
 *  Purpose: Calculates the total of N integers, N<=100.
 *
 *  @author Jaye Smith
 *  @version 8/20/19
 */

// Some function prototypes

/**
 *  Calculates the sum of the first N integers in an array.
 *
 *  @param a array containing at least N integers.
 *  @param N the number of elements to add.
 *  @return the sum of the N elements a[0] through a[N-1].
 */
int sum( int a[] , unsigned int a )

{
  int add = 0;
  for(int i = 0;i<N;i++)
    add+=a[i];
  return add;

}

/**
 *  Calculates the minimum of the first N>0 integers in an array.
 *
 *  @param a array containing at least N integers.
 *  @param N the number of elements to search from.
 *  @return the minimum of the N elements a[0] through a[N-1].
 */
int min( int a[] , unsigned int a )

{
  int min=a[0];
  for(int i=0;i<N;i++)
  {
    if(a[i]<min)
    {
        min=a[i];
    }
  }
  return min;
}
/**
 *  Calculates the maximum of the first N>0 integers in an array.
 *
 *  @param a array containing at least N integers.
 *  @param N the number of elements to search from.
 *  @return the maximum of the N elements a[0] through a[N-1].
 */
int max( int a[] , unsigned int a )
{
int max=a[0];
for(int i=0;i<N;i++)
  {
    if(max<a[i])
    max=a[i];
  }
}

/**
 *  Calculates the average of the first N>0 integers in an array.
 *
 *  @param a array containing at least N integers.
 *  @param N the number of elements to calculate the average of.
 *  @return the average of the N elements a[0] through a[N-1].
 */
float average( int a[] , unsigned int a )
{
  float avg=0.0f;
  int add1=0;
  for(int i=0;i<=N;i++)
  {
    add1+=a[i];
  }
  avg=add1/N;
  return avg;
}

#include <iostream>
using namespace std;

int main() {
	// Your code goes here
	int x[];
	cout<<"Enter the array";
	cin>>x[];

	cout<<"Count   = "<<x.length;
	cout<<"minimum = "<<minimum(x,x.length);
	cout<<"maximum = "<<maximum(x,x.length);
	cout<<"sum     = "<<sum(x,x.length);
	cout<<"average = "<<average(x,x.lengh);

	return 0;
}
