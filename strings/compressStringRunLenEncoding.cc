#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    string s="aaabbbccdddeff";
    int p1 = 0;
    int p2 = 0;

    string cs;
    int len = s.length();

    while(p1 < len)
    {
        int count = 0;
        while(p2 < len && s[p1] == s[p2])
        {
            p2++;
            count++;
        }
        cs += s[p1] + to_string(count);
        p1 = p2;
    }

    cout << cs << endl;
    return 0;
}