#include <iostream>

using namespace std;

int binSearch(int arr[], int key, int l, int r)
{
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
        {
            l = mid + 1;
        }

        if (arr[mid] > key)
        {
            r = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {10, 22, 33, 44, 55, 66, 77, 88, 99};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = binSearch(arr, 55, 0, n - 1);
    if (k != -1)
    {
        cout << "Found at index " << k;
    }

    return 0;
}