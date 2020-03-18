#ifndef POLY_H
#define POLY_H

#include <string>
using namespace std;


// default size of our dynamic coefficient array
const int DEFAULTPOLY = 50;    

class Poly
{

private:

  // Data members   [implementation of ADT's data object]
  // Feel free to change to meet your needs.

  int maxPoly;    // size of array
  double *coeff;     // dynamic array



public:

  // Default Class constructor
  // Allocate an array of DEFAULTPOLY elements and initializes it to the constant 0
  // post: Class object is initialized to degree-0 polynomial of 0  
  Poly ();

  // Non-default (alternate) Class constructor
  // Allocate an array of 'size' elements and initializes it to the constant 0
  // post: Class object is initialized to degree-0 polynomial of 0  
  Poly (int size);

  // Copy constructor
  // Construct a new Poly that is a copy of an existing Poly
  // post: Class object is initialized to be a copy of the argument Poly
  Poly (const Poly& aPoly);

  // Destructor
  // Destroy a poly object by freeing the dynamically allocated array
  ~Poly ();

  // Assignment operator
  // Assign rhs Poly object to 'this' Poly object
  const Poly& operator= (const Poly& rhs);



  // Member functions   [specs for ADT's operations]

  // maxSize
  // Return the size of the coefficient array
  int maxSize() const;


  // grow
  // This method will allow us to increase the size of the dynamically allocated
  // array by allocating a new array of the desired size, copying the data from
  // the old array to the new array, and then releasing the old array.
  // If the newSize is less than or equal to the current size, then no actions 
  // are taken.
  // Note: the maximum degree of a polynomial is one less than the size of the 
  // array. The parameter newSize represents the size of the array.
  void grow (int newSize);


  // degree
  // Finds the degree of a polynomial (the highest power with a
  //    non-zero coefficient)
  // pre: Class object exists
  // post: Returns the degree of the polynomial object.
  int getDegree () const;

  // setCoeff
  // Sets a term, value*x^i, in a polynomial, growing the array if necessary.
  // pre: Class object has been initialized. 0 <= i.
  // post: In the polynomial, the term with power i has coefficient
  //       value. The polynomical was grown if required.
  // Throws <std::out_of_range> if index i does not meet the precondition.
  void setCoeff (double value, int i);

  // retrieveCoeff
  // Finds the coefficient of the x^i term in poly
  // pre: Class object has been initialized. 0 <= i
  // post: Returns the value of the coefficient of the term with power i
  // note: If the object does not contain a term with power i (e.g., 
  //       i>=maxPoly), a coefficient value of zero is returned.
  // Throws <std::out_of_range> if index i does not meet the precondition.
  double coefficient (int i) const;

  // incrementCoeff
  // Changes a term, value*x^i, in a polynomial, growing the polynomial if required.
  // pre: Class object has been initialized. 0 <= i.
  // post: In the Class object the term with power i has its coefficient
  //       incremented by the given value. The array has grown if necessary.
  // Throws <std::out_of_range> if index i does not meet the precondition.
  // void incrementCoeff (double value, int i);

  // toString  
  // Produce a string representation of a Poly object
  // pre: The class object has been initialized.
  // post: A string representation is returned.
  // dependencies: This function requires that the degree() and 
  //  retrieveCoeff() functions are implemented.
  // note: This function has been provided for you -- DO NOT CHANGE IT!
  string toString () const;

  // numOfTerms
  // Returns the number of terms in the polynomial.
  // pre: The class object has been initialized.
  // post: The number of non-zero terms of the polynomial is returned.
  int numOfTerms () const;

  // evaluate
  // Evaluate a polynomial for a specified value of X
  // pre: The class object has been initialized
  // post: The polynomial will be evaluated for the value of
  //       X received as an argument. The resulting value is
  //       returned.
  double evaluate (double x) const;

  // add
  // Add one polynomial to another
  // pre: The class object has been initialized. The received
  //       argument is also an initialized poly object.
  // post: The argument polynomial is added to the object polynomial.
  //       The object polynomial is changed to hold the sum. The object
  //       polynomial is grown if required to hold the resulting sum.
  // Note: the poly object being operated upon may be of a different
  //   size (maxPoly) than the aPoly parameter. If the aPoly parameter
  //   has a degree larger than the array in the 'this' Poly object,
  //   then the array is grown large enough to hold the sum.
  void addTerm(int i, double value)

  void setTerm(int i, double value)

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
  void subtract (const Poly& aPoly);

  // addition operator
  // Add two polynomials together and return a new polynomial that is the result
  // pre: The class object has been initialized. The received
  //       argument is also an initialized poly object.
  // post: The argument polynomial is added to the object polynomial, and the
  //       result is stored in a new polynomial which is returned.
  //       The object polynomial is not changed.
  // note: This function has been provided for you -- DO NOT CHANGE IT!
  Poly operator+ (const Poly& rhs) const;

  // subtraction operator
  // Subtracts one polynomial from another and return a new polynomial that is the result
  // pre: The class object has been initialized. The received
  //       argument is also an initialized poly object.
  // post: The argument polynomial is subtracted from the object polynomial, and the
  //       result is stored in a new polynomial which is returned.
  //       The object polynomial is not changed.
  // note: This function has been provided for you -- DO NOT CHANGE IT!
  Poly operator- (const Poly& rhs) const;

  // equals
  // Determine if two polynomials are equal
  // pre: The class object has been initialized. The received
  //       argument is also an initialized poly object.
  // post: Returns true if the two polynomials are equal, false otherwise.
  bool equals (const Poly& aPoly) const;

  // Equality/inequality operators
  // note: These functions have been provided for you -- DO NOT CHANGE IT!
  bool operator== (const Poly& rhs) const;
  bool operator!= (const Poly& rhs) const;


  // negate
  // Negate a polynomial
  // pre: The class object has been initialized.
  // post: The polynomial has been changed to represent its
  //       multiplication by -1.0.
  void negate ();

  // multByConst
  // Multiply a polynomial by a constant
  // pre: The class object has been initialized.
  // post: The polynomial has been changed to represent its
  //       multiplication by the value of argument val.
  void multByConst (double val);

  // derivative
  // Compute the derivative of a polynomial
  // pre: The class object has been initialized.
  // post: The polynomial has been changed to represent its
  //       derivative.
  void derivative ();


  // insertion operator for output
  // note: This function has been provided for you -- DO NOT CHANGE IT!
  friend ostream& operator<< (ostream& os, const Poly &p);
#endif
};