// Sample program using the split() function to tokenize a string
//Author: Padam Rana

#include <iostream>
#include <sstream>  // for istringstream
#include <vector>
#include "ArrayPolynomial.h"
using namespace std;

/** Function to split a string into tokens
    @param s The string that needs to be split into tokens.
    @param delimeter The character used to delimit/separate tokens.
    @return  A string vector containing the tokens in string s. */
    
    vector<string> split( const string& s , char delimiter )
    {
        vector<string> tokens;          // vector of tokens
        string token;                   // a single token
        istringstream tokenStream(s);   // an input string stream

        // Tokenize s by grabbing individual tokens
        while( getline( tokenStream , token , delimiter ) )
            tokens.push_back(token);    // add found token

        return tokens;
    }

/** Sample use in function main() of a driver */

int main()
{
    ArrayPolynomial DOTA;
    string input;                 // input string to hold 1 line from cin
    char   delimiter = ' ';       // what separates tokens in the input string
    vector<string> listOfTokens;  // store tokens of input here
    int array[30];
    vector<string> v;
    int flag=0;
    int sum=0;

   
    // Read in a string as a line of text from standard input.
    
    while( getline( cin , input ) ) 
    {

        

        if(flag==0)
        {
            listOfTokens = split( input , delimiter );
            for(int i=0; i<listOfTokens.size();i++)
            {
                //cin>>array[i];
                if(i<31){
                array[i] = stoi(listOfTokens[i]);
            }
                 //cout<<"Array 1 is "<<array[i]<<endl;
            }
        
        }
        else
        {
            v = split( input , delimiter );

            for(int i=0; i<v.size();i++)
            {
                // v.push_back(i);
              // cout<<"Array 2 is"<<v[i]<<endl;
              
  int degree = listOfTokens.size();
 
                if(i==0){
               cout << DOTA.horner(array, degree, stoi(v[i])) ;//calling function to calculate polynomial using horner
           }
           else{
            cout << " "<<DOTA.horner(array, degree, stoi(v[i])) ;
           }
      
            }
        flag=0;
        cout << endl;
        continue;
        }


        // Use the split() function above to extract tokens
        

        // Display the tokens individually:
        // cout << "There are " << listOfTokens.size() << " tokens:" << endl;
      
        //cout << endl; // separates each output
        flag++;
    }    
}