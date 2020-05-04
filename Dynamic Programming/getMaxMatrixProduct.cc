// Given a matrix, find the path from top left to bottom right with the greatest product by
// moving only down and right

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int findMaxProductTLToBR(vector<vector<int>> &mat)
{
    int maxCache[mat.size()][mat[0].size()];
    int minCache[mat.size()][mat[0].size()];
 
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            int maxVal = numeric_limits<int>::min();
            int minVal = numeric_limits<int>::max();

            if (i == 0 && j == 0)
            {
                maxVal = mat[i][j];
                minVal = mat[i][j];
            }

            if (i > 0)
            {
                int tmpMax = std::max(mat[i][j] * maxCache[i - 1][j], mat[i][j] * minCache[i - 1][j]);
                maxVal = max(maxVal, tmpMax);
                int tmpMin = std::min(mat[i][j] * maxCache[i - 1][j], mat[i][j] * minCache[i - 1][j]);
                minVal = min(minVal, tmpMin);
            }

            if (j > 0)
            {
                int tmpMax = std::max(mat[i][j] * maxCache[i][j-1], mat[i][j] * minCache[i][j-1]);
                maxVal = max(maxVal, tmpMax);
                int tmpMin = std::min(mat[i][j] * maxCache[i][j-1], mat[i][j] * minCache[i][j-1]);
                minVal = min(minVal, tmpMin);
            }

            maxCache[i][j] = maxVal;
            minCache[i][j] = minVal;
        }
    }
    
    return maxCache[mat.size()-1][mat[0].size()-1];
}

int main()
{
    vector<vector<int>> mat = {{1, 2, 3},
                               {4, 5, 6},
                               {7, 8, 9}};

    int maxVal = findMaxProductTLToBR(mat);

    cout << maxVal << endl;

    return 0;
}