// File: templated_node_function.cpp
// Prepared by bjuliano@csuchico.edu

// This is an example of how templated functions can be used
// to work for multiple types. Note that templated functions
// can be called explicitly or implcitly (see below).

// This code also shows how to create linked lists using a
// predefined Node class (Carrano & Henry, 2017).

#include <iostream>
#include <string>
#include <random>    // to generate uniform integer distributions
#include "Node.h"
using namespace std;

// Template function to insert an item into a linked list
template< class T >
void insert( Node<T>* &headPtr , const T& entry )
{
	// Create a new node and have the next pointer point to current front
	Node<T> *newNodePtr = new Node<T>( entry , headPtr );
	// Current front now becomes this new node
	headPtr = newNodePtr;
}

// Template function to display the contents of a linked list
template< class T >
void display( Node<T> *headPtr )
{
	Node<T> *currNodePtr = headPtr;
	while( currNodePtr ) // as long as not nullptr
	{
		cout << currNodePtr->getItem() << endl;
		currNodePtr = currNodePtr->getNext();
	}
}

// Driver to read words from standard input (via cin) inserting
// them one at a time into an initially empty linked list.
// When input is exhausted, the contents of the linked list are
// displayed one word per line to standard output (via cout).

template< class T >
void sum(Node<T>* headPtr) 
{ 
	int a=0;
   /* if (!head) 
        return; 
    sum(head->next, sum); 
    	*sum = *sum + head->data; 8*/

	Node<T> *currNodePtr = headPtr;
	while( currNodePtr ) // as long as not nullptr
	{a+= currNodePtr->getItem();
		
		currNodePtr = currNodePtr->getNext();
		
	}
	cout<<"Sum: "<< a;
	//return a;

} 

template< class T >
int Max(Node<T>* head)
{
	int max=-100000;
	while(head!=NULL)
	{
		if(max < head->getItem())
			max=head->getItem();
		head=head->getNext();
	}
	return max;
	
}
template< class T >
void Rev(Node<T>* p)
{
	if (p==NULL)
	{
		//head=p;
		return;
	}
	Rev(p->getNext());
	cout << p->getItem() << " ";
	//struct Node* q=p->getNext();
	//q->next=p;
	//p->next=NULL;
}
int main()
{
	/*// Declare a linked list of strings
	Node<string> *listOfStrings = nullptr;
	*/
	// Declare a linked list of ints
	Node<int> *listOfIntegers = nullptr;


	// Read words and insert each one into a linked list
	int element;
	int count=0;
	while( cin >> element ){
	    insert<int>( listOfIntegers , element );
		count++;
	}
		if(count==0){
			cout<<"Contents: <EMPTY>"<<endl;
		}
   else{
	// Display the contents of the integer linked list
	cout<<"Contents: ";
	Rev<int>( listOfIntegers ); cout << endl;
    sum<int>( listOfIntegers ); cout << endl;
	cout<<"Maximum: "<<Max<int>( listOfIntegers ) << endl;
	}


	return 0;
}