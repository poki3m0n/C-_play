#include <iostream>
#include <cmath>
#include "LinkedPolynomial.h"

using namespace std;

LinkedPolynomial::LinkedPolynomial() {
	listOfEntries = nullptr;
	degree = 0;	
}

bool LinkedPolynomial::isZero() const
{
	return listOfEntries==nullptr;
}
unsigned LinkedPolynomial::getDegree() const
{
	return degree;
}
void LinkedPolynomial::clear()
{
	Node<Tm> *crntNode;
	crntNode = listOfEntries;
	while ( crntNode ){
		Node<Tm> *nxtNode = crntNode->getNext();
		delete(crntNode);
		crntNode = nxtNode;
	}
	degree = 0;
}
bool LinkedPolynomial::addTerm(double coeff, unsigned exp)
{
	Tm entryTerm (exp, coeff);
	Node<Tm> *&headPtr= listOfEntries;
	Node<Tm> *new_node = new Node<Tm>(entryTerm, headPtr); 
	headPtr = new_node;
	return true;
}

double LinkedPolynomial::evaluate(double y) const
{	
	double ans=0.0;
	return ans;
}

double LinkedPolynomial::evalDerivative(double y) const
{
	double ans=0.0;
	// Node<Tm> *head = ;
	Node<Tm> *crntPtr = listOfEntries;

	while ( crntPtr ) {
			unsigned expo = crntPtr->getItem().first;
		double coeff = crntPtr->getItem().second;
		// cout << coeff << " " << expo << " | ";
		if((int)expo-1 <= 0 || coeff == 0)
		{	
			ans += 0;
			// ans +=? 0;
			// break;
		} else {
			ans += expo*coeff*pow(y, (expo-1));
			// cout << coeff <<  <<endl;
			// cout << expo << "*" << coeff << "*" << y << "^" << expo-1 << " | ";
		}
		crntPtr = crntPtr->getNext();
	}
	// cout << ans << endl;	
	// cout << endl;
	return ans;
}

void LinkedPolynomial::print() const {  }