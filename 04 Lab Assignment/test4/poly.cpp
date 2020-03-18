#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cmath>
#include "Poly.h"
using namespace std;


// Default Class constructor
// Allocate an array of DEFAULTPOLY elements and initializes it to the constant 0
// post: Class object is initialized to degree-0 polynomial of 0  
Poly::Poly()
{
    coeff = new double [DEFAULTPOLY];
    for (int i = 0; i < (int) DEFAULTPOLY; i++)
    {
        coeff[i] = 0.0;
    }
    maxPoly = DEFAULTPOLY;
}

// Non-default (alternate) Class constructor
// Allocate an array of 'size' elements and initializes it to the constant 0
// post: Class object is initialized to degree-0 polynomial of 0  
Poly::Poly(int size)
{
    coeff = new double[size];
    for (int i = 0; i < (int) size; i++)
    {
        coeff[i] = 0.0;
    }
    maxPoly = size;
}

// Copy constructor
// Construct a new Poly that is a copy of an existing Poly
// post: Class object is initialized to be a copy of the argument Poly
Poly::Poly(const Poly& aPoly)
{
    coeff = new double[aPoly.maxPoly];
    for (int i = 0; i < (int) aPoly.maxPoly; i++)
    {
        coeff[i] = aPoly.coeff[i];
    }
    maxPoly = aPoly.maxPoly;
}

// Destructor
// Destroy a poly object by freeing the dynamically allocated array
Poly::~Poly()
{
    delete[] coeff;
}

// Assignment operator
// Assign rhs Poly object to 'this' Poly object
const Poly& Poly::operator= (const Poly& rhs)
{
    if (this == &rhs){
        return *this;
    }
    Poly tmp(rhs);
    std::swap(maxPoly, tmp.maxPoly);
    std::swap(coeff, tmp.coeff);
    return *this;
}


//////////////////////////////////////////////////
//
// Member functions   [specs for ADT's operations]
//
//////////////////////////////////////////////////

// maxSize
// Return the size of the coefficient array
int Poly::maxSize() const
{
    int maxSize = maxPoly;
    return maxSize;
}

// grow
// This method will allow us to increase the size of the dynamically allocated
// array by allocating a new array of the desired size, copying the data from
// the old array to the new array, and then releasing the old array.
// If the newSize is less than or equal to the current size, then no actions 
// are taken.
// Note: the maximum degree of a polynomial is one less than the size of the 
// array. The parameter newSize represents the size of the array.
void Poly::grow(int newSize)
{
    int arrSize = (int) maxPoly;
    if ((int) newSize > arrSize)
    {
        double* newArrPtr = new double[newSize];
        for (int i = 0; i < arrSize; i++)
        {
            newArrPtr[i] = coeff[i];
        }
        std::swap(newArrPtr, coeff);
        std::swap(newSize, maxPoly);
    }

}

// degree
// Finds the degree of a polynomial (the highest power with a
//    non-zero coefficient)
// pre: Class object exists
// post: Returns the degree of the polynomial object.
int Poly::getDegree() const
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


// setCoeff
// Sets a term, value*x^i, in a polynomial, growing the array if necessary.
// pre: Class object has been initialized. 0 <= i.
// post: In the polynomial, the term with power i has coefficient
//       value. The polynomical was grown if required.
// Throws <std::out_of_range> if index i does not meet the precondition.
void Poly::setCoeff(double value, int i)
{
    if ((int)0 <= i && i <= maxPoly)
    {
        if (i > maxPoly)
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

// retrieveCoeff
// Finds the coefficient of the x^i term in poly
// pre: Class object has been initialized. 0 <= i
// post: Returns the value of the coefficient of the term with power i
// note: If the object does not contain a term with power i (e.g., 
//       i>=maxPoly), a coefficient value of zero is returned.
// Throws <std::out_of_range> if index i does not meet the precondition.
double Poly::coefficient(int i) const
{
    if (0 <= (int)i)
    {
        return coeff[i];
    }
    else if (i >= (int)maxPoly)
    {
        return 0.0;
    }
    else
    {
        throw std::out_of_range("Index out of range");
    }
}

// incrementCoeff
// Changes a term, value*x^i, in a polynomial, growing the polynomial if required.
// pre: Class object has been initialized. 0 <= i.
// post: In the Class object the term with power i has its coefficient
//       incremented by the given value. The array has grown if necessary.
// Throws <std::out_of_range> if index i does not meet the precondition.
void Poly::setTerm(int i, double value)
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

void Poly::addTerm(int i, double value)
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

// toString  
// Produce a string representation of a Poly object
// pre: The class object has been initialized.
// post: A string representation is returned.
// dependencies: This function requires that the degree() and 
//  retrieveCoeff() functions are implemented.
// note: This function has been provided for you -- DO NOT CHANGE IT!
string Poly::toString() const
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

// numOfTerms
// Returns the number of terms in the polynomial.
// pre: The class object has been initialized.
// post: The number of non-zero terms of the polynomial is returned.
int Poly::numOfTerms() const
{
    int numTerms = 0;
    for (int i = 0; i < (int)maxPoly; i++)
    {
        if (coeff[i] != 0)
        {
            numTerms++;
        }
    }
    return numTerms;
}

// evaluate
// Evaluate a polynomial for a specified value of X
// pre: The class object has been initialized
// post: The polynomial will be evaluated for the value of
//       X received as an argument. The resulting value is
//       returned.
double Poly::evaluate(double x) const
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

// addTerm
// addTerm one polynomial to another
// pre: The class object has been initialized. The received
//       argument is also an initialized poly object.
// post: The argument polynomial is addTermed to the object polynomial.
//       The object polynomial is changed to hold the sum. The object
//       polynomial is grown if required to hold the resulting sum.
// Note: the poly object being operated upon may be of a different
//   size (maxPoly) than the aPoly parameter. If the aPoly parameter
//   has a degree larger than the array in the 'this' Poly object,
//   then the array is grown large enough to hold the sum.
void Poly::add(const Poly& aPoly)
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


// subtract
// Subtract one polynomial from another
// pre: The class object has been initialized. The received
//       argument is also an initialized poly object.
// post: The argument polynomial is subtracted from the object polynomial.
//       The object polynomial is changed to hold the result. The object
//       polynomial is grown if required to hold the result.
// Note: the poly object being operated upon may be of a different
//   size (maxPoly) than the aPoly parameter. If the aPoly parameter
//   has a degree larger than the array in the 'this' Poly object,
//   then the array is grown large enough to hold the result.
void Poly::subtract(const Poly& aPoly)
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

// addTermition operator
// addTerm two polynomials together and return a new polynomial that is the result
// pre: The class object has been initialized. The received
//       argument is also an initialized poly object.
// post: The argument polynomial is addTermed to the object polynomial, and the
//       result is stored in a new polynomial which is returned.
//       The object polynomial is not changed.
// note: This function has been provided for you -- DO NOT CHANGE IT!
Poly Poly::operator+ (const Poly& rhs) const
{
    Poly result;
    result.add(*this);
    result.add(rhs);
    return result;
}

// subtraction operator
// Subtracts one polynomial from another and return a new polynomial that is the result
// pre: The class object has been initialized. The received
//       argument is also an initialized poly object.
// post: The argument polynomial is subtracted from the object polynomial, and the
//       result is stored in a new polynomial which is returned.
//       The object polynomial is not changed.
// note: This function has been provided for you -- DO NOT CHANGE IT!
Poly Poly::operator- (const Poly& rhs) const
{
    Poly result;
    result.subtract(*this);
    result.subtract(rhs);
    return result;
}

// equals
// Determine if two polynomials are equal
// pre: The class object has been initialized. The received
//       argument is also an initialized poly object.
// post: Returns true if the two polynomials are equal, false otherwise.
bool Poly::equals(const Poly& aPoly) const
{
    if (maxPoly != aPoly.maxPoly)
    {
        return(false);
    }
    for (int i = 0; i < (int) maxPoly; i++)
    {
        if (aPoly.coeff[i] != coeff[i])
        {
            return(false);
        }
    }
    return(true);
}

// Equality/inequality operators
// note: These functions have been provided for you -- DO NOT CHANGE IT!
bool Poly::operator== (const Poly& rhs) const
{
    return equals(rhs);
}

bool Poly::operator!= (const Poly& rhs) const
{
    return !equals(rhs);
}


// negate
// Negate a polynomial
// pre: The class object has been initialized.
// post: The polynomial has been changed to represent its
//       multiplication by -1.0.
void Poly::negate()
{
    multByConst(-1.0);
}

// multByConst
// Multiply a polynomial by a constant
// pre: The class object has been initialized.
// post: The polynomial has been changed to represent its
//       multiplication by the value of argument val.
void Poly::multByConst(double val)
{
    double* tmpArray = new double[maxPoly];
    for (int i = 0; i < (int)maxPoly; i++)
    {
        tmpArray[i] = retrieveCoeff((int)i) * val;
    }
    std::swap(tmpArray, coeff);
}

// derivative
// Compute the derivative of a polynomial
// pre: The class object has been initialized.
// post: The polynomial has been changed to represent its
//       derivative.


// insertion operator for output
// note: This function has been provided for you -- DO NOT CHANGE IT!
ostream & operator << (ostream &out, const Poly& p)
{
    out << p.toString();
    return out;
}