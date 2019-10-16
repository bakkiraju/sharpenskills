#include <bits/stdc++.h>

using namespace std;

#define N 4
bool isSafe(vector<vector<int> > &mat, int r, int c)
{
    for (int i = 0; i < c; i++)
    {
        if (mat.at(r).at(i))
            return false;
    }

    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
    {
        if (mat.at(i).at(j))
            return false;
    }

    for (int i = r, j = c; i < N && j >=0; i++, j--)
    {
        if (mat.at(i).at(j))
            return false;
    }

    return true;
}

void printNQueens(vector<vector<int> > &mat, int c)
{
    if (c == N)
    {
        for (auto v : mat)
        {
            for (auto e : v)
            {
                cout << e << " ";
            }

            cout << endl;
        }
        cout << endl;
        return ;
    }

    for (int r=0; r < N; r++)
    {
        if (isSafe(mat, r, c))
        {
            mat.at(r).at(c) = 1;

            printNQueens(mat, c + 1);

            mat.at(r).at(c) = 0;
        }
    } 
}

int main()
{
    vector<int> v(N,0);

    vector<vector<int> > mat(N,v);

    printNQueens(mat, 0);

    return 0;
}