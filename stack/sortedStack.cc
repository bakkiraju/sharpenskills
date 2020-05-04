/* Sort up the stack without using any extra space */
/* Use recursion: Recursion will create function call stack frames 
  and those stack frames will provide us space to store and sort 
  the values in the original stack
*/

#include <iostream>
#include <stack>

using namespace std;

// Note: pass by reference
void insertBack(stack<int> &st, int item)
{
    if (st.empty() or item > st.top())
    {
        st.push(item);
        return;
    }

    int x = st.top();
    st.pop();
    insertBack(st, item);
    st.push(x);
}

// Note: pass by reference
void sortStack(stack<int> &st)
{
    if (not st.empty())
    {
        int item = st.top();
        st.pop();
        sortStack(st); // pour all the content out into call frame stack
        insertBack(st, item); // stat inserting back
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
    st.push(2);
    sortStack(st);
    printStack(st);
    return 0;
}