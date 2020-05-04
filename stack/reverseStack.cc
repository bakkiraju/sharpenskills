/*Reverse a stack without using any extra space */
/* Use recursion: Recursion will create function call stack frames 
  and those stack frames will provide us space to store and reverse 
  the values in the original stack
*/

#include <iostream>
#include <stack>

using namespace std;

void insertBack(stack<int> &st, int item)
{
    if (st.empty())
    {
        st.push(item);
        return;
    }
    int x = st.top();
    st.pop();
    insertBack(st, item);
    st.push(x);
}

void reverse(stack<int> &st)
{
    if (not st.empty())
    {

        int temp = st.top();
        st.pop();
        reverse(st);
        insertBack(st, temp);
    }
}

void printStack(stack<int> st)
{
    while (not st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> st;
    st.push(11);
    st.push(14);
    st.push(4);
    st.push(12);
    reverse(st);
    printStack(st);
    return 0;
}