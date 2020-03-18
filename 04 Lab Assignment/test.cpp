#include <iostream>
#include <vector>
#include <sstream>
#include "Polynomial.h"

using namespace std;

vector<string> split( const string& s , char delimiter ) {
    vector<string> tokens;          // vector of tokens
    string token;                   // a single token
    istringstream tokenStream(s);   // an input string stream

    // Tokenize s by grabbing individual tokens
    while( getline( tokenStream , token , delimiter ) )
        tokens.push_back(token);    // add found token

    return tokens;
}

vector<double> readInputs(string inp, char del){
    vector<string> temp = split(inp, del);
    vector<double> inputValues;
    for (unsigned i = 0; i < temp.size(); i++)
        inputValues.push_back(stod(temp[i])); // adding values to temp vector
    return inputValues;
}

int main(){
    unsigned testCases = 0;
    char del = ' ';
    vector < Polynomial > f;
    vector < Polynomial > g;
    vector < vector<double> > polF;
    vector < vector<double> > polG;
    vector < vector<double> > vals;
    bool polFFlag = true, polGFlag = false, valsFlag = false;
    string input;
    while ( getline(cin, input) ){
        if(polFFlag && !polGFlag && !valsFlag){
            vector<double> temp = readInputs(input, del);
            reverse(temp.begin(), temp.end());
            polF.push_back(temp);
            polFFlag = false;
            polGFlag = true;
        } else if (!polFFlag && polGFlag && !valsFlag){
            vector<double> temp = readInputs(input, del);
            reverse(temp.begin(), temp.end());
            polG.push_back(temp);
            polGFlag = false;
            valsFlag = true;
        } else if (!polFFlag && !polGFlag && valsFlag){
            vals.push_back(readInputs(input, del));
            valsFlag = false;
            polFFlag = true;
        }
    }
    testCases = polF.size();
    for (unsigned i = 0; i < polF.size(); i++){
        Polynomial fTemp;
        for (unsigned j = 0; j < polF[i].size(); j++){
            // fTemp.addTerm(j,polF[i][polF[i].size() - j]);
            fTemp.addTerm(j, polF[i][j]);
        }
        f.push_back(fTemp);
    }
    for (unsigned i = 0; i < polG.size(); i++){
        Polynomial fTemp;
        for (unsigned j = 0; j < polG[i].size(); j++){
            // fTemp.addTerm(j,polF[i][polF[i].size() - j]);
            fTemp.addTerm(j, polG[i][j]);
        }
        g.push_back(fTemp);
    }

    for (unsigned i = 0; i < testCases; i++){
        cout << "TEST CASE #" << i+1 << endl;
        cout << "f: ";
        f[i].display();
    }

    return 0;
}

// -2
// 1 -1
// 5 0 1 6