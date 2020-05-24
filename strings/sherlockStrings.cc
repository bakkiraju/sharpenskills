#include <iostream>
#include <unordered_map>
#include <string>
#include <climits>

using namespace std;

string isValid(string s)
{
    unordered_map<char, int> m;
    for (auto ch : s)
    {
        m[ch]++;
    }

    int min = INT_MAX;
    int max = INT_MIN;

    for (auto p : m)
    {
        if (p.second > max)
        {
            max = p.second;
        }

        if (p.second < min)
        {
            min = p.second;
        }
    }

    if (min == max)
        return "YES";

    bool cond1 = true, cond2 = true;

    unordered_map<char, int> m1 = m;

    // remove one min occuring element and check if everything else equal is max
    for (auto &p : m)
    {
        if (p.second == min)
        {
            p.second--;
            break;
        }
    }

    for (auto &p : m)
    {
        if (p.second != 0 && p.second != max)
        {
            cond1 = false;
        }
    }

    // remove one max occurring element and check everything now is equal to min
    for (auto &p : m1)
    {
        if (p.second == max)
        {
            p.second--;
            break;
        }
    }

    for (auto p : m1)
    {
        if (p.second != 0 && p.second != min)
        {
            cond2 = false;
        }
    }

    return (cond1 || cond2) ? "YES" : "NO";
}

int main()
{
    string s = "aabbccddeefghi";
    cout << isValid(s) << endl;
    return 0;
}