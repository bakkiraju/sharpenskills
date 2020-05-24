#include<iostream>
#include<string>

using namespace std;

bool isSubSequence(string s, string t)
{
    int lb = s.length(), rb = t.length();
    int ps=0, pt=0;

    while (ps < lb && pt < rb)
    {
        if (s[ps] == t[pt])
        {
            ps++;
        }
        pt++;
    }

    return (ps == lb);
}

int main()
{
   string s = "abc";
   string t = "ahbgdc";
   
   cout << (isSubSequence(s,t) ? "Yes" : "No") << endl;

   return 0;
   
}