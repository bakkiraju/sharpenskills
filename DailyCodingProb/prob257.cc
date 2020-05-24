/*
Given an array of integers out of order, determine the bounds of the smallest window 
that must be sorted in order for the entire array to be sorted. For example, 
given [3, 7, 5, 6, 9], you should return (1, 3).
*/

#include <vector>
#include <limits>
#include <iostream>

using namespace std;

int main()
{
    //vector<int> v{3, 7, 5, 6, 9};
    vector<int> v{1, 2, 7, 5, 6, 3, 9};
    int l = 0, r = v.size() - 1;
    int min_idx = numeric_limits<int>::max();
    int max_idx = numeric_limits<int>::min();
    bool swapped = false;

    for (int j = 0; j < v.size() - 1; j++)
    {
        l = j;
        r = v.size()-1;
        swapped = false;
        while (l < r)
        {
            if (v[l] < v[r])
            {
                l++;
                r--;
            }
            else if (v[l] > v[r])
            {
                if (min_idx > l)
                {
                    min_idx = l;
                }

                if (max_idx < r)
                {
                    max_idx = r;
                }
                swapped = true;
                swap(v[l],v[r]);
                r--;
            }
            else
            {
                l++;
            }
        }

        if (not swapped)
           break;
    }
 
    cout << min_idx << " " << max_idx << endl;
    return 0;
}