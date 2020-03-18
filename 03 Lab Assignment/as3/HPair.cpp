// File: templated_node_function.cpp
// Prepared by bjuliano@csuchico.edu

// This is an example of how templated functions can be used
// to work for multiple types. Note that templated functions
// can be called explicitly or implcitly (see below).

// This code also shows how to create linked lists using a
// predefined Node class (Carrano & Henry, 2017).

#include <iostream>
#include <string>
#include <sstream>	
#include <random>    // to generate uniform integer distributions
#include "Node.h"
#include <queue>
#include "LinkedPolynomial.h"

using namespace std;

vector<string> split( const string& s , char delimiter )
{
	vector<string> tokens; // vector of tokens
	string token; // a single token
	istringstream tokenStream(s); // an input string stream

	// Tokenize s by grabbing individual tokens
	while( getline( tokenStream , token , delimiter ) )
	tokens.push_back(token); // add found token

	return tokens;
 }

 /** Clean up a string of special/invisible characters.
    @param str The string that needs to be "cleaned".
    @return The cleaned up version of str. */
    
    string removeSpecials( string str )
    {
   	    int i=0,len=str.length();
   	    while(i<len) // Check every character
   	    {
            char c=str[i];
            if( !(((c>='0')&&(c<='9')) || ((c>='A')&&(c<='Z')) || ((c>='a')&&(c<='z')) || (c==' ') || (c=='-')) ) 
            {
                str.erase(i,1); // Delete "bad" character
                --len;          // and adjust length
            }
            i++;
        }
        return str;
    }

int main()
{
	// Node<double> *listOfValues = nullptr;
	queue< vector <double> > results;
	string data="";
	char delimiter = ' ';
	bool flag = true;
	
	LinkedPolynomial polynomial;
	while( getline(cin, data) )
	{
		// cout << endl;
		if(flag)
		{
			polynomial.clear();
			vector<string> tempData = split(data, delimiter);
			for ( unsigned i = 0; i < tempData.size(); i++){
				//  cout << tempData[i] << " " << tempData.size() - i - 1 << " | ";
			polynomial.addTerm(stod(tempData[i]), tempData.size() - i - 1);
			}
			// cout << endl;
			flag = !flag;
		} 
		else 
		{
			vector<string> tempData = split(data, delimiter);
			vector<double> temp;
			for ( unsigned i = 0; i < tempData.size(); i++)
			{
				// cout << tempData[i] << " | ";
				double tmp = polynomial.evalDerivative(stod(tempData[i]));
				// cout << tmp << " | ";
				temp.push_back(tmp);
			}
			// cout << endl;
			results.push(temp);
			temp.clear();
			polynomial.clear();
			flag = !flag;
		}
	}
	
	for ( unsigned i = 0; i < results.size(); i++){
		for ( unsigned j = 0; j < results.front().size(); j++){
			cout << results.front()[j];
			if (j+1 != results.front().size()) cout << " ";
		}
		results.pop();
		
	}
cout << endl;

	return 0;
}