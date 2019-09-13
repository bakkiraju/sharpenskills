/* Return the number of [a-z] chanracter encodings possible for a given numeric string */

#include <bits/stdc++.h>

using namespace std;

int encodeStr(const string s, int size)
{
    int count=1;
    int flag = 0;
    if (size==1) {
        if (s[0] == '0')
            return 0;
        else
            return 1;
    }

    int k = 0;
    while (s[k] == '0')
    {
        k++;
        if (k == size) return 0;
    }

    // go in window of len 2 and see if [a-z] encoding is possible
    for(size_t i=k; i < size-1; i++)
    {
       if (s[i] =='0' && s[i+1] == '0') return 0;

       if (s[i] =='0' && s[i+1] != '0') {flag =1; continue; }

       if (s[i] !='0' && s[i+1] == '0') {flag =1; }

      // std::cout << s[i]  << " " << s[i+1] << std::endl;

       if ( s[i] <= '2' && s[i+1] <= '6')
       {
           count +=1;
       }
    }

    if (flag) count --;

    return count;
}


int main()
{
   string s;
   std::cout << "Enter numeric string and see number of ways it can be decoded:" << std::endl;
   while( getline(std::cin, s))
   {
      if (not s.length()) break;

      int ways = encodeStr(s, s.size());
      cout << "ways: " << ways << endl;
   }

   return 0;
}