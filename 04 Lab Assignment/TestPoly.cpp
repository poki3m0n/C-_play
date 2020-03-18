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
#include <queue>
#include "Polynomial.h"

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

int main()
{   
    string input1;                 // input string to hold 1 line from cin
    string input2;
    string input3;  
    char   delimiter = ' ';       // what separates tokens in the input string
    vector <double>  polynomial_f;
    vector <double>  polynomial_g;
    vector <double>  polynomial_value;
    int flag = 0;
    Polynomial poly;

    while(flag<=2)
    {
        getline(cin, input1);
        vector<string> tempData1 = split(input1, delimiter);
        vector<double> temp1;
        for ( unsigned i = 0; i < tempData1.size(); i++)
        {
            reverse(tempData1.begin(),tempData1.end());
            double temp1 = (stod(tempData1[i]));
            polynomial_f.push_back(temp1);
            p.evaluate(temp1);
        }
        getline(cin, input2);  
        vector<string> tempData2 = split(input2, delimiter);
        vector<double> temp2;
        for ( unsigned i = 0; i < tempData2.size(); i++)
        {
            reverse(tempData2.begin(),tempData2.end());
            double temp2 = (stod(tempData2[i]));
            polynomial_g.push_back(temp2);
        }
    
        getline(cin, input3); 
        vector<string> tempData3 = split(input3, delimiter);
        vector<double> temp3;
        for ( unsigned i = 0; i < tempData3.size(); i++)
        {
            reverse(tempData3.begin(),tempData3.end());
            double temp3 = (stod(tempData3[i]));
            polynomial_value.push_back(temp3);
        }

        

        flag++;
    }


}