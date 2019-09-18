/* Goal : Paint N houses from K available colors such that no two adjacent houses have same color.
   A cost matrix is provided for colors, find minimum colors
*/
#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> TWODarray;

int findMinCost(int N, int K, TWODarray &costs)
{
    for (int h=1; h < N; h++)
    {
        for (int c = 0; c < K; c++)
        {
            int min_cost = INT_MAX;
            for (int j = 0; j < K; j++)
            {
                if (j == c) continue;
                if (costs[h-1][j] < min_cost)
                {
                    min_cost = costs[h-1][j];
                }
            }
            costs[h][c] += min_cost;
        }
        //  costs[h][0] += min(costs[h-1][1], costs[h-1][2]);
        //  costs[h][1] += min(costs[h-1][0], costs[h-1][2]);
        //  costs[h][2] += min(costs[h-1][0], costs[h-1][1]);
    }

    int min_cost = INT_MAX;
    for (int j = 0; j < N; ++j)
    {
        if (costs[j][K-1] < min_cost)
           min_cost = costs[N-1][j];
    }

    return min_cost;

   // return std::min(costs[N-1][0], std::min(costs[N-1][1], costs[N-1][2]));
}

int main()
{
    int N = 3;
    int K = 3;

    vector<vector<int>> cost = {
                          {1, 2, 3},
                          {2, 1, 4},
                          {9, 11, 6}
                      };

    int price = findMinCost(N, K, cost);

    cout << "Cost : " << price << endl;

    return 0;
}