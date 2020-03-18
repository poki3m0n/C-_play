#ifndef LINKED_POLYNOMIAL_
#define LINKED_POLYNOMIAL_

#include <vector>
#include "PolynomialInterface.h"
#include"Node.h"
using namespace std;

class LinkedPolynomial : public PolynomialInterface
{
private:
	typedef pair<unsigned, double > Tm;
	unsigned degree;
	Node<Tm> *listOfEntries;
public:
	Tm term;
	LinkedPolynomial();
	
	bool isZero() const;
	unsigned getDegree() const;
	bool addTerm(double coeff, unsigned exp);
	double evaluate(double x) const;
	double evalDerivative(double x) const;
	void clear();
	void print() const;
};

#include"LinkedPolynomial.cpp"
#endif