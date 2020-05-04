// Leetcode : filepath to cannoical 
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string simplifyPath(string path, string dir = {}, vector<string> stack = {}) {
        transform(path.begin(), path.end(), path.begin(), [](auto c) { return c == '/' ? ' ' : c; });
        
        for (istringstream stream{ path }; stream >> dir;)
            if (dir != "." && dir != "..")
                stack.push_back(dir);
            else if (dir == ".." && !stack.empty())
                stack.pop_back();

        stringstream stream;
        for (auto& dir: stack)
            stream << "/" << dir;
        string ans = stream.str();
        return ans.empty() ? "/" : ans;
    }


int main()
{
    string s{"/../"};
    cout << simplifyPath(s) << endl;
    return 0; 
}