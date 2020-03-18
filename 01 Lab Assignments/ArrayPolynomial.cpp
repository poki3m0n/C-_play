#include<iostream>
/* 
int evaluate(i)
{
	int cal;
	cal=cal+
	for (auto i = path.begin(); i != path.end(); ++i)
    std::cout << *i << ' ';
}
  void tokenize()
{
	vector<int> myNumbers;
	while(cin>>input)
		myNumbers.push_back(stoi(input));
}*/
//logic forcalculating the polynomial values
int ArrayPolynomial::horner(int poly[], int n, int x) 
{ 
    int result = poly[0];  // Initialize result 
  
    // Evaluate value of polynomial using Horner's method 
    if(n>30){
    	n=30;
    }
    for (int i=1; i<n; i++) 
        result = result*x + poly[i]; 
    
   //  cout << "result-" << result << endl;
    return result; 
} 
bool ArrayPolynomial::isZero() const
{
	return add==0;
}
unsigned ArrayPolynomial::getDegree() const
{
	return power;
}
void ArrayPolynomial::clear()
{
	add=0;
}
bool ArrayPolynomial::addTerm(double coeff, unsigned exp)
{
	return add=0;
}
double ArrayPolynomial::evaluate(double y) const
{
	return 0;
}
void ArrayPolynomial::print() const
{
	cout<<printl;
}