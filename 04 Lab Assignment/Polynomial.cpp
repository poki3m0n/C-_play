#include <iostream>
#include <cmath>
#include "Polynomial.h"

using namespace std;

Polynomial::Polynomial()
{
    coeff = new double [DEFAULTPOLY];
    for (int i = 0; i < (int) DEFAULTPOLY; i++)
    {
        coeff[i] = 0.0;
    }
    maxPoly = DEFAULTPOLY;
}
Polynomial::Polynomial(const Poly& aPoly) 	//copy constructor
{
    coeff = new double[aPoly.maxPoly];
    for (int i = 0; i < (int) aPoly.maxPoly; i++)
    {
        coeff[i] = aPoly.coeff[i];
    }
    maxPoly = aPoly.maxPoly;
}

const Polynomial& Polynomial::operator= (const Poly& rhs)
{
    if (this == &rhs){
        return *this;
    }
    Poly tmp(rhs);
    std::swap(maxPoly, tmp.maxPoly);
    std::swap(coeff, tmp.coeff);
    return *this;
}

Polynomial::~Polynomial() // destructor
{
    delete[] coeff;
}
bool Polynomial::isZero() const
{
 return listOfEntries==nullptr;
}
unsigned Polynomial::getDegree() const
{
	int degree = 0;
    for (int i = 0; i < (int)maxPoly; i++)
    {
        if (coeff[i] != 0)
        {
            degree = (int)i;
        }
    }
    return degree;
}
void Polynomial::clear()
{

}
bool Polynomial::addTerm(unsigned exponent, double coefficient)
{
return 0;	
}
double Polynomial::coefficient(unsigned exponent) 
{
	if ((int)0 <= i && i <= maxPoly)
    {
        if (i > maxPoly)
        {
            grow(i);
        }
        coeff[i] = value;
    }
}

void Polynomial::setTerm(unsigned i, double value)
{
    if (0 <= (int)i)
    {
        if (i > (int)maxPoly)
        {
            grow(i);
        }
        coeff[i] = value;
    }
    else
    {
        throw std::out_of_range("Index out of range");
    }

}

void Polynomial::addTerm(unsigned i, double value)
{
    if (0 <= (int)i)
    {
        if (i > (int)maxPoly)
        {
            grow(i);
        }
        coeff[i]+ = value;
    }
    else
    {
        throw std::out_of_range("Index out of range");
    }

}
string Polynomial::display() const
{
    ostringstream result;
    bool printedSomething = false;
    for (int i = (int)degree(); i >= 0; i--)
    {
        double c = retrieveCoeff(i);
        if (c != 0.0)
        {
            printedSomething = true;
            if (i == 0)
            {
                result.setf(ios::showpos);
                result << " " << c;
                result.unsetf(ios::showpos);
            }
            else
            {
                result.setf(ios::showpos);
                result << " " << c;
                result.unsetf(ios::showpos);
                result << "*X^" << i;
            }
        }
    }
    if (!printedSomething)
    {
        result.setf(ios::showpos);
        result << " " << 0;
        result.unsetf(ios::showpos);
    }
    return result.str();

}

double Polynomial::evaluate(double y) const
{
    double polyTotal = 0.0;
    double coeff = 0.0;
    for (int i = 0; i < (int) maxPoly; i++)
    {
        coeff = retrieveCoeff((int) i);
        polyTotal += (coeff * pow(x, (double)i));
    }
    return polyTotal;
}
void Polynomial::add_polynomial(const Poly& aPoly)
{
    if (aPoly.maxPoly > maxPoly)
    {
        grow(aPoly.maxPoly);
    }
    for (int i = 0; i < (int)maxPoly; i++)
    {
        coeff[i] += aPoly.coeff[i];
    }
}
void Polynomial::subtract(const Poly& aPoly)
{
    if (aPoly.maxPoly > maxPoly)
    {
        grow(aPoly.maxPoly);
    }
    for (int i = 0; i < (int) maxPoly; i++)
    {
        coeff[i] -= aPoly.coeff[i];
    }
}
Poly Poly::operator+ (const Poly& rhs) const
{
    Poly result;
    result.add(*this);
    result.add(rhs);
    return result;
}
Poly Poly::operator- (const Poly& rhs) const
{
    Poly result;
    result.subtract(*this);
    result.subtract(rhs);
    return result;
}

bool Poly::operator== (const Poly& rhs) const
{
    return equals(rhs);
}
ostream & operator << (ostream &out, const Poly& p)
{
    out << p.toString();
    return out;
}

bool Poly::operator!= (const Poly& rhs) const
{
    return !equals(rhs);
}