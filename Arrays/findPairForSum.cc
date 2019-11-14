#include <iostream>
#include <unordered_map>

using namespace std;

void findPair(int arr[] , int n, int sum)
{
    unordered_map<int, int> map;

    for (int i=0; i < n; i++)
    {
        if (map.find(arr[i]) != map.end())
        {
            cout << "Found pair: " << arr[i] << " " << sum-arr[i] << endl;
        }

        map[sum-arr[i]] = i;
    }

    return;
}

int main()
{
    int arr[ ] = {8, 7, 2, 5, 3, 1};
    int sum = 10;
    int n = sizeof(arr) / sizeof(arr[0]);

    findPair(arr, n, sum);

    return 0;
}