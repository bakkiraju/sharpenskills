/* Daily Coding Problem 216 : Roman numeral to decimal */
#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

/*
   VI = { 5, 1 }  -> 1 + 5 = 6
   IV = { 1 , 5 } -> 5 - 1 = 4
*/

int main()
{
    unordered_map<char, int> r2d = {
        {'M', 1000},
        {'D', 500},
        {'C', 100},
        {'L', 50},
        {'X', 10},
        {'V', 5},
        {'I', 1}};
    
    stack<char> st;

    string s = "XIV";
 
    for (char ch : s)
    {
        st.push(ch);
    }

    int sum = 0;
    int num;
    char ch = st.top();
    if (r2d.find(ch) != r2d.end())
    {
        num = r2d[ch];
    }
    
    sum += num;
    st.pop();
    int prev = num;

    while (not st.empty())
    {
        ch = st.top();
        
        if (r2d.find(ch) != r2d.end())
        {
            num = r2d[ch];  
        }

        if (num < prev)
        {
            sum -= num;
        }
        else 
        {
            sum += num;     
        }
 
        prev = num;
        st.pop();
    }

    cout << sum << endl;

    return 0;
}