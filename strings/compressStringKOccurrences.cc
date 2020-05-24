#include <iostream>
#include <stack>

using namespace std;

struct  MyStruct
{
    char ch;
    int count;
};

typedef struct MyStruct count_t;

string compress(string s, int K)
{
    stack<count_t> st;
    for(int i = 0; i < (int)s.length(); i++)
    {
        if(not st.empty() && st.top().ch == s[i])
        {
            count_t ct;
            ct.ch = s[i];
            ct.count = st.top().count+1;
            if (ct.count == K)
            {
                for(int i=0; i < K-1; i++)
                {
                    st.pop();
                }
            }
            else
            {
                st.push(ct);
            }
        }
        else
        {
            count_t ct;
            ct.ch = s[i];
            ct.count = 1;
            st.push(ct);
        }
    }

    string ts="";
    while(not st.empty())
    {
        count_t t = st.top(); st.pop();
        ts += t.ch;
    }

    return ts =="" ? "" : string(ts.rbegin(),ts.rend());
}

int main()
{
    stack<count_t> st;
    cout << "compressed string:" << compress("abbcccba", 3) << endl;
    cout << "compressed string:" << compress("abbcccbadd", 3) << endl;
    cout << "compressed string:" << compress("deeedbbcccbdaa", 3) << endl;
    return 0;
}