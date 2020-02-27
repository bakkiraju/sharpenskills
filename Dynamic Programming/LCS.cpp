#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int LCSHelper(string X, string Y, int m, int n, unordered_map<string, int> &cache)
{
    if (m ==  0 || n == 0) return 0;

    string key = to_string(m)+'|'+to_string(n);

    if (cache.find(key) != cache.end())
    {
        return cache[key];
    }
    else
    {
        if (X[m - 1] == Y[n - 1])
        {
            cache[key] = LCSHelper(X, Y, m - 1, n - 1, cache) + 1;
        }
        else
        {
            cache[key] = max(LCSHelper(X, Y,m-1, n, cache), LCSHelper(X, Y, m, n-1, cache));
        }
    }

    return cache[key]; 
}

int LCS(string X, string Y)
{
    unordered_map<string, int> cache;
    return LCSHelper(X, Y, X.length(), Y.length(), cache);
}

int main()
{
    string X = "ABCBDAB", Y = "BDCABA";
    cout << LCS(X, Y) << endl;
}