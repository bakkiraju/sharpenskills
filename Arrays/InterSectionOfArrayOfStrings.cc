#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

string intersect(std::string &A, std::string &B)
{
    multiset<char> s{A.begin(), A.end()};
    string str;
    for (char e : B)
    {
        auto it = s.find(e);
        if (it != s.end())
        {
            s.erase(it);
            str.append(1, e);
        }
    }

    return str;
}

vector<string> commonChars(vector<string> &A)
{
    if (A.size() == 0)
        return {};
    string s = A[0];
    for (int i = 1; i < A.size(); i++)
    {
        s = intersect(s, A[i]);
    }

    vector<string> res;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        string str(1, *it);
        res.push_back(str);
    }

    return res;
}

int main()
{
    vector<string> v{string("bella"), string("label"), string("roller")};
    vector<string> res = commonChars(v);

    for(auto e : res)
    {
        cout << e << " ";
    }

    cout << endl;

    return 0;
}