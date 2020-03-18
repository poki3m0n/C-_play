#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <algorithm>

using namespace std;
typedef pair<int, string> pairs; 
typedef pair<string,int> pairs2; 
bool found;

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
// void cartesian::prompt() {

// 	std::cout << "Enter integers for set A (no more than 30 numbers, -1 to stop)\n";
	
// 		for (int i = 0; i < size; i++) {
// 			int Avalue;
// 			std::cout << (i+1) << ": ";
// 			std::cin >> Avalue;
			
// 			if (Avalue != -1 ) this->A.push_back(Avalue);
// 			else break;
// 		}

// 		std::cout << "\nEnter characters for set B (no more than 30 numbers, '.' to stop)\n";

// 		for (int j = 0; j < size; j++) {
// 			std::string Bvalue;
// 			std::cout << (j+1) << ": ";
// 			std::cin >> Bvalue;

// 			if (Bvalue != ".") this->B.push_back(Bvalue);
// 			else break;
// 		}

// }

// void cartesian::create_pair() {
// 	int Asize = this->A.size();
// 	for (int i = 0; i < Asize ; i++) {

// 	this->elements.insert(std::make_pair(this->A[i], this->B));

		

// 	}

set<pairs> b;
set<pairs2> c;

int main()
{
	unsigned flag=0;
	string data;
    vector<string> ints;
    vector<string> chars;
    unsigned counter=0;
    unsigned counter2=0;
    char delimiter = ' ';

  while (getline(cin,data))
  {
	if(flag%2==0)
	{
		chars = split(data, delimiter);
	}
	else
		ints = split(data, delimiter);
	flag++;
  }
  //AXB
  	sort(ints.begin(),ints.end());
	sort(chars.begin(),chars.end());
	for(unsigned i=0;i<ints.size();i++)
	{
	//  cout << "first-" << ints[i] << endl;
		for(unsigned j=0;j<chars.size();j++)
		{
		//  cout << "second-" << chars[j] << endl;
			pairs x = make_pair(stoi(ints[i]),chars[j]);
			b.insert(x);
		}
	}

for(unsigned i=0;i<chars.size();i++)
{
//  cout << "first-" << ints[i] << endl;
	for(unsigned j=0;j<ints.size();j++)
	{
	//  cout << "second-" << chars[j] << endl;
		pairs2 y = make_pair(chars[i],stoi(ints[j]));
		c.insert(y);
	}
}

  cout<<"Given: A={";
  for(unsigned x=0;x<chars.size();x++)
  	{
		  if(counter>0){
		cout << ",";
	}
		  cout << chars[x];
		  counter++;
	  }
	  cout << "}";
	  cout << endl;
counter = 0;
cout<<"       B={";
  for(unsigned x=0;x<ints.size();x++)
  	{
		  if(counter>0){
		cout << ",";
	}
		  cout << ints[x];
		    counter++;
	  }
	  cout << "}";
	  cout << endl;
counter = 0;
	cout <<"Then AxB={";
	for (auto const &x : c) 
	{ 
	found = true;
	  if(counter2>0){
		cout << ",";
	}
	cout << "(" << x.first << ","
             << x.second << ")"; 
			 counter2++;

	}
	cout << "}";
	cout << endl;
	cout <<"     BxA={";
	

	for (auto const &x : b) 
	{ 
	found = true;
    if(counter>0){
		cout << ",";
	}
	cout << "(" << x.first << ","
			<< x.second << ")"
			; 
	 counter++;
	} 
	cout << "}";
	cout << endl;
}