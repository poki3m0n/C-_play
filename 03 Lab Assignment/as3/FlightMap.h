#ifndef MAP_INTERFACE_
#define MAP_INTERFACE_

#include <vector>
#include "MapInterface.h"
#include"Node.h"
using namespace std;

class MapInterface : public MapInterface
{
private:
	typedef pair<unsigned, double > Tm;
	unsigned degree;
	Node<Tm> *listOfEntries;
public:
	Tm term;
	MapInterface();
	
	void read() const;
	unsigned getDegree() const;
	bool addTerm(double coeff, unsigned exp);
	double evaluate(double x) const;
	double evalDerivative(double x) const;
	void clear();
	void print() const;
};

#include"LinkedPolynomial.cpp"
#endif