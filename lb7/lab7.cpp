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
template<class T>

void insert( Node<T>* &headPtr , const unsigned& new_node_value )
{
	Node<T> *currentptr;
	Node<T> *new_node = new Node<T>(new_node_value, headPtr); 

	if (headPtr== nullptr ||  headPtr->getItem() >= new_node_value)
	{
		new_node->setNext(headPtr);
		headPtr = new_node;
	} 
	else 
	{
		currentptr = headPtr;
		while ( currentptr->getNext() != nullptr && currentptr->getNext()->getItem() < new_node_value)
		{	

          currentptr=currentptr->getNext();
		}
		new_node->setNext(currentptr->getNext());
        currentptr->setNext(new_node);
			/*prev = currentptr;
			currentptr = currentptr->getNext();
			
			if (new_node < currentptr->getItem())
			{
				new_node->setNext(currentptr);
				prev->setNext(new_node);
			}*/
	}
}

	// if (currentptr == nullptr && new_node < currentptr->getItem()) {
	// 	new_node->setNext(currentptr);
	// 	headPtr = new_node;
	// }

//	while(currentptr!= nullptr && new_node < currentptr->getItem())
//	{
//		node<unsigned> *prev = headPtr;
//		new_node -> current;
//		prev->new_node;
//		currentptr-> getNext();
//		insert();	
//		currNodePtr = currNodePtr->getNext();
//	}
//	if (!(currentptr!= nullptr && new_node < currentptr->getItem())){

//	}

	// while( currNodePtr ) // as long as not nullptr
	// {
	// 	cout << currNodePtr->getItem() << endl;
	// 	currNodePtr = currNodePtr->getNext();
	// }


 template< class T >
int removeEvens( Node<T>* &headPtr)
{
	Node<T> *prev = headPtr;
	Node<T> *currentptr= headPtr;
	int total_evens=0;
	int e_count=0;
	while(currentptr!=NULL) 
    {
    	if(prev->getItem()%2 == 0)
    	{
    		//cout << "Item-" << prev->getItem() << endl;
          prev->setItem(prev->getNext()->getItem());
          prev->setNext(prev->getNext()->getNext());
          total_evens++;
    	}

    	else if(currentptr->getItem()%2 == 0)
    	{	
    		//cout << "Item2-" << currentptr->getItem() << endl;
    		Node<T> *temp = new Node<T>(currentptr->getItem(),headPtr);
    		prev->setNext(currentptr->getNext());
			free(temp);

    		// prev->setNext()=current->setNext();
    		// currentptr->getNext();
    		// prev=currentptr;
    		// prev
    		total_evens++;
    	}
    	else{
    	prev = currentptr;
    }
    	    	currentptr = currentptr->getNext();

        e_count++;
    }
    return total_evens; 

}


// Driver to read words from standard input (via cin) inserting
// them one at a time into an initially empty linked list.
// When input is exhausted, the contents of the linked list are
// displayed one word per line to standard output (via cout).

/*template< class T >
void sum(Node<T>* headPtr) 
{ 
	int a=0;
   /* if (!head) 
        return; 
    sum(head->next, sum); 
    	*sum = *sum + head->data; 8

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
}*/
template< class T>
void display(Node<T> *headPtr)
{
	while(headPtr)
	{
		cout<<" "<<headPtr->getItem();
		headPtr=headPtr->getNext();
	}
}
int main()
{
	/*// Declare a linked list of strings
	Node<string> *listOfStrings = nullptr;
	*/
	// Declare a linked list of ints
	Node<int> *listOfIntegers = nullptr;


	// Read words and insert each one into a linked list
	int evens=0;
	int items_left=0;
	int element;
	int count=0;
	while( cin >> element ){
	    insert<int>( listOfIntegers , element );
		count++;
	}
		if(count==0){
			cout<<"Sorted list (0 elements):"<<endl;
			cout<<endl;
			cout<<"Found 0 even numbers"<<endl;
			cout<<"List with even numbers removed (0 elements):"<<endl;
			cout<<endl;
		}
   else{
	// Display the contents of the integer linked list
	cout<<"Sorted list ("<<count<<" elements):"<<endl;
	display<int>( listOfIntegers ); cout << endl;
 	evens = removeEvens<int>(listOfIntegers);
 	cout << "Found "<< evens << " even numbers"  << endl;
	items_left = count - evens;
	cout << "List with even numbers removed (" << items_left << " elements):" << endl;
	display<int>( listOfIntegers ); cout << endl;
	//cout<<"Maximum: "<<Max<int>( listOfIntegers ) << endl;
	return 0;
	}

}