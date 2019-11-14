#include <iostream>
#include <vector>

using namespace std;
#define N 3

int main()
{
    vector<vector<int> > cost_mat(N, vector<int>(N));

    for (int i=0; i < N; i++)
    {
        cost_mat.at(0).at(i) = 1;
        cost_mat.at(i).at(0) = 1;
    }

    for (int i=1; i < N; i++)
    {
        for (int j=1; j < N; j++)
        {
            cost_mat.at(i).at(j) = cost_mat.at(i-1).at(j) + cost_mat.at(i).at(j-1);
        }
    }

    cout << "Num of ways to go from top left to bottom right:" << cost_mat.at(N-1).at(N-1) << endl;

    return 0;
}