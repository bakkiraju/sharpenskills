#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int sherlockAndAnagrams(string s) {

   //find all the substrings
    unordered_map<string, int> m;

    for(int i=0; i < s.length(); i++)
    {
        string subs="";
        for (int j=i; j < s.length(); j++)
        {
            subs += s[j];
            //cout << subs << endl;
            string ss = subs;
            sort(ss.begin(), ss.end());
            m[ss]++;
        }
    }

    int cnt = 0;  
    for (auto p : m)
    {
        if (p.second > 1)
        {
            cnt += (p.second) * (p.second-1)/2;
        }
    }

    return cnt;
}

int main()
{
    string s = "abcd";
    cout << sherlockAndAnagrams(s) << endl;
    return 0;
}