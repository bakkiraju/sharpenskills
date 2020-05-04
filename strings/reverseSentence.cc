#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <algorithm>

using namespace std;

// step 1 : hello there happy world 
// step 2 : dlrow yppah ereht olleh
// step 3 : world happy there hello
void reverseInPlace(string &str)
{
    int n = static_cast<int>(str.length());
    int start = 0, end = 0;
    std::reverse(str.begin(), str.end());
    while (end < n)
    {
        if (str[end] != ' ')
        {
            start = end;
            while (end < n && str[end] != ' ') end++;
            std::reverse(str.begin()+start, str.begin()+end);
        }
        end++;
    }
}

int main()
{
    string s = "data structures and algorithms practice"; 
    reverseInPlace(s);
    cout << s << endl;
    return 0;   
}
