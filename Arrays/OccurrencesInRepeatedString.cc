// https://www.hackerrank.com/challenges/repeated-string/problem
// Complete the repeatedString function below.
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

long repeatedString(string s, long n) {

    int c = std::count(s.begin(), s.end(),'a');
    if (c == 0) return 0;

    if (s.size() == 1) return n;
    
    auto m = n/s.length();
    auto r = n%s.length();
    return m*c +std::count(s.begin(), s.begin()+r, 'a');
}

int main()
{
    cout << repeatedString("abc",10);
    return 0;
}