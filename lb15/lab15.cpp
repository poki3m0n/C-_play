#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

// vector<string> split( const string& s , char delimiter )
// {
//     vector<string> tokens;          // vector of tokens
//     string token;                   // a single token
//     istringstream tokenStream(s);   // an input string stream

//     // Tokenize s by grabbing individual tokens
//     while( getline( tokenStream , token , delimiter ) )
//         tokens.push_back(token);    // add found token

//     return tokens;
// }
void print_output (vector <tuple <int, int> > path)//(int path)
{
    for ( unsigned i = 0; i < path.size(); i++ )
        cout << "(" << get<0>(path[i]) << "," << get<1>(path[i]) << ") ";
    cout << endl;
    // for (auto i = path.begin(); i != path.end(); ++i)
        // cout << *i << ' ';
}
bool fTfE(const tuple<int,int>& a,const tuple<int,int>& b)
{
    return (get<0>(a) < get<0>(b));
}
bool fTsE(const tuple<int,int>& a,const tuple<int,int>& b)
{
    return (get<0>(a) > get<0>(b));
}

bool sTfE(const tuple<int,int>& a,const tuple<int,int>& b)
{
    return (get<1>(a) < get<1>(b));
}
bool sTsE(const tuple<int,int>& a,const tuple<int,int>& b)
{
    return (get<1>(a) > get<1>(b));
}
int main()
{
    string data;
    // vector<string> inputs;
    int intOne, intTwo;
    
    vector<string> tempData;
    vector < tuple <int,int> > tempData1;
    // char delimiter = ' '; 
    while( cin >> data) //getline(cin, data) ) 
    {
        tempData.push_back(data); // = split(data, delimiter);
    }

    for(unsigned i=0;i<tempData.size();i++)
    { 
        intOne = stoi(tempData[i]);
        i++;
        intTwo = stoi(tempData[i]);
        tempData1.push_back(make_tuple(intOne,intTwo));
    }
    sort(tempData1.begin(), tempData1.end(),fTfE);
    print_output(tempData1);

    sort(tempData1.begin(), tempData1.end(),fTsE);
    print_output(tempData1);
    cout<<endl;

    sort(tempData1.begin(), tempData1.end(),sTfE);
    print_output(tempData1);

    sort(tempData1.begin(), tempData1.end(),sTsE);
    print_output(tempData1);
    cout<<endl;

    return 0;
}