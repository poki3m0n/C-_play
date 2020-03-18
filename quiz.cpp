#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
using namespace std;
int main ()
{
  unordered_set<string> myset;
  string input;
   ifstream data;
   data.open("ABC.txt");
   if(data.is_open())
   {
       while(getline(data, input))
        {
            myset.insert(input);
        }
   }
    data.close();
    
  unsigned n = myset.bucket_count();

  cout << "myset has " << n << " buckets.\n";

  for (unsigned i=0; i<n; ++i) {
    cout << "bucket #" << i << " contains:";
    for (auto it = myset.begin(i); it!=myset.end(i); ++it)
      cout << " " << *it;
    cout << "\n";
  }

  return 0;
}