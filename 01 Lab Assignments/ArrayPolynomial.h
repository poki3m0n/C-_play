#ifndef ARRAY_POLYNOMIAL_H	
#define ARRAY_POLYNOMIAL_H

#include <vector>
#include "PolynomialInterface.h"
using namespace std;

class ArrayPolynomial : public PolynomialInterface
{
private:
	unsigned power;
	unsigned add;
	double printl;
	
public:
	int horner(int poly[], int n, int x); 
	void setgame(int arr[], vector<string> a, int size);
	bool isZero() const;
	unsigned getDegree() const;
	bool addTerm(double coeff, unsigned exp);
	double evaluate(double x) const;
	void clear();
	void print() const;
};

#include"ArrayPolynomial.cpp"
#endif