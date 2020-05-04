// Given a string with repeated characters, rearrange the string so that no two adjacent characters are the same. 
// If this is not possible, return None.

#include <iostream>
#include <map>
#include <string>

using namespace std;
/*
  aabbbc = ababcb
  aabbb = babab
  aabb = abab
*/
int main()
{
   const string s("aaaabbbc");
   map<char,int> m;

   for(char ch : s)
   { 
       if (m.find(ch) == m.end())
       {
           m[ch] = 1;
       }
       else
       {
           m[ch] += 1;
       }
   }

   int max_freq = 0;
   for (auto e : m)
   {
      if (max_freq < e.second)
      {
          max_freq = e.second;
      }
   }

   if (max_freq <= (s.length() - max_freq + 1))
      cout <<  "Possible";
   else 
      cout << "None";

   return 0; 
}