#include <sstream>  // for istringstream

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

/** Sample use in function main() of a driver:

    string input;                 // input string to hold 1 line from cin
    char   delimiter = ' ';       // what separates tokens in the input string
    vector<string> listOfTokens;  // store tokens of input here

    // Read in a string as a line of text from standard input.
    while( getline( cin , input ) ) {

        // Use the split() function above to extract tokens
        listOfTokens = split( input , delimiter );

        // Rest of code goes here ...
    }

*/