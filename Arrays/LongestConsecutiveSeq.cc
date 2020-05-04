// Longest consecutive sequence of an unsorted array
// 1. can wrap around multiple times to pick the next successive number to form longest sequence.
// 2. cannot wrap around, must go through array once and pick longest sequence.

#include <iostream>
#include <set>
#include <vector>
#include <limits>

using namespace std;

void longestSeqWrapAround(vector<int> &arr)
{
    set<int> s;

    for (auto elem : arr)
    {
        s.insert(elem);
    }

    int maxLen = numeric_limits<int>::min();

    int start, end;

    for (auto it=s.begin(); it != s.end(); it++)
    {
        int elem = *it;
        if (s.find(elem - 1) != s.end())
            continue;
        int length = 0;
        while (s.find(elem) != s.end())
        {
            ++length;    
            ++elem;
        }

        if (length > maxLen)
        {
            maxLen = length;
            start = elem - length;
            end = elem-1;     
        }
    }

    cout << maxLen << " [" << start << "," << end << "]" << endl;
}

void longestSeqNoWrap(vector<int> &arr)
{
   int maxLength = numeric_limits<int>::min();
   int length = 1;
   int start, end;
   for (int i=0;i<arr.size(); i++)
   {
       start = arr[i]; 
       while ((i < arr.size()-1) && (arr[i] + 1 == arr[i+1]))
       {
          length++;
          i++;
       }
       end = arr[i];
       if (length > maxLength) maxLength = length;
   }

   cout << maxLength << " [" << start << "," << end << "]" << endl;
}

int main()
{
    vector<int> arr = {6, 1, 4, 7, 3, 14, 25};
    longestSeqWrapAround(arr);
    longestSeqNoWrap(arr);
    return 0;
}