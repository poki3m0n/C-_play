#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
#include <iterator>
#include <utility>

using namespace std;

vector<string> split( const string& s , char delimiter )
{
	vector<string> tokens; // vector of tokens
	string token; // a single token
	istringstream tokenStream(s); // an input string stream

	// Tokenize s by grabbing individual tokens
    
	while( getline( tokenStream, token , delimiter ) )
	    tokens.push_back(token); // add found token

	return tokens;
 }

int main()
{
	vector <string> heap;
    vector <int> ints;
	string data="";
	string data2="";
	char delimiter = ' ';
	bool flag = false;
	int index;
	index =-1;
    while(getline(cin, data))
	{
		ints.clear();
		heap.clear();
		heap = split(data, delimiter);
		for ( unsigned i = 0; i < heap.size(); i++)
		{
            ints.push_back(stoi(heap[i]));
        }
		if (ints.size() == 1)
            flag = true; 
		else
		 {
            for ( int i = ints.size()/2-1; i >= 0; --i)
			{
                if ((2*i+2) <= ints.size()-1)
				{
                    if (ints[i] <= ints[2*i+1] && ints[i] <= ints[2*i+2])
					{
                        flag = true;
                    } else 
					{
                        flag = false;
                        index = i;
                        
                        break; 
                	}
                } 
				else 
				{
                    if (ints[i] <= ints[2*i+1])
					{
                        flag = true; 
                    } 
					else 
					{
                        flag = false;
                        index = i;
                        break; 
                    }
                }
            }
        }
        
        if (flag) data2 += "Vector is a min-heap.\n";
        else data2 += "Min-heap structure property violated at index " + to_string(index) + ".\n";
        flag = false;
    }
    cout << data2;
    return 0;
}
	