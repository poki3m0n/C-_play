#include <iostream>
#include <string>
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
	string input1;  
    char   delimiter = ' ';       // what separates tokens in the input string
    queue< vector <double> > polynomial_f;
    queue< vector <double> > polynomial_g;
    queue< vector <double> > polynomial_value;
    int flag = 0;
	getline(cin, input1);
	vector<string> tempData1 = split(input1, delimiter);
	vector<double> temp1;
	for ( unsigned i = 0; i < tempData1.size(); i++)
	{
		reverse(tempData1.begin(),tempData1.end());
		double temp1 = (stod(tempData1[i]));
		// cout << tmp << " | ";
		polynomial_f.push_back(temp1);
	}
	
    return 0;
}