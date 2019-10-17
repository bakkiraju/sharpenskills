#include <iostream>
#include <set>
#include <vector>
#include <iterator>

using namespace  std;


bool checkDuplicatesWithinK(int arr[], int n, int k) 
{ 
    // Creates an empty hashset 
    set<int> myset; 
  
    // Traverse the input array 
    for (int i = 0; i < n; i++) 
    { 
        // If already present n hash, then we found 
        // a duplicate within k distance 
        if (myset.find(arr[i]) != myset.end()) {
            cout << "found:" << arr[i] << endl;
            return true; 
        }
  
        // Add this item to hashset 
        cout << "Inserting :" << arr[i] << endl;
        myset.insert(arr[i]); 
  
        // Remove the k+1 distant item 
        if (i >= k) 
        {
            cout << "removing :" << arr[i-k] << endl;
            myset.erase(arr[i-k]); 
        }
    } 
    return false; 
} 
  
// Driver method to test above method 
int main () 
{ 
    int arr[] = {10, 5, 3, 4, 3, 5, 6}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    if (checkDuplicatesWithinK(arr, n, 3)) 
        cout << "Yes"; 
    else
        cout << "No"; 
} 