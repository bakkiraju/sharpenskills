#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int longestPeak(vector<int> array)
{
    if (array.size() == 0)
        return 0;
    vector<int> peaks;
    for (int j = 1; j < array.size() - 1; j++)
    {
        if (array[j - 1] < array[j] && array[j] > array[j + 1])
        {
            peaks.push_back(j);
        }
    }

    if (peaks.size() == 0)
        return 0;

    int max_len = 3;

    for (int i = 0; i < peaks.size(); i++)
    {
        int len = 3;
        int lidx = peaks.at(i) - 2;
        while (lidx >= 0 && array.at(lidx) < array.at(lidx + 1))
        {
            lidx--;
            len++;
        }
        int ridx = peaks.at(i) + 2;
        while (ridx < array.size() && array.at(ridx) < array.at(ridx - 1))
        {
            ridx++;
            len++;
        }
        if (len > max_len)
            max_len = len;
    }
    return max_len;
}

int main()
{
    vector<int> v{1, 2, 3, 3, 4, 0, 10, 6, 5, -1, -3, 2, 3};
    cout << "Length of longest peak : " << longestPeak(v) << endl;
    return 0;
}