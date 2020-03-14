/* problem 197
   Roatate Array In Place

   [1, 2, 4, 6, 8 , 9], k = 2
   [8, 9, 1, 2, 4, 6]

   for (int j=0; j < k; j++)
   {
   tmp = arr[n-1]
   for(int i = n-1; i > 0 ; i--)
   {
        move arr[i-1] to arr[i]
   }
   arr[0] = tmp;
   }
*/

#include <vector>
#include <iostream>
#include <assert.h>

using namespace std;

void rotate_iter(vector<int> &arr, int k)
{
    int n = arr.size();

    for (int j=0; j < k; j++)
    {
        int tmp = arr[n-1];
        for(int i = n-1; i > 0 ; i--)
        {
             arr[i] = arr[i-1];
        }
        arr[0] = tmp;
    }

     for (auto elem: arr)
    {
        cout << elem << " ";
    }
  
}

void rotate_byrev(vector<int> &arr, int k)
{
    if (k > arr.size()) return;
    // reverse n-k, n-1 
    int right  =  arr.size()-1; 
    int left =  arr.size()-k;
    
    while (left < right)
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }  
    // reverse n-k-2, 0 
    right  =  arr.size()-k-1; 
    left =  0;
    
    while (left < right)
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }  

    for(auto i=arr.rbegin(); i!=arr.rend(); i++)
    {
        cout << *i << " ";
    }

    cout << endl;
}

int main()
{
    vector<int> arr{1,2,4,6,8,9};
    int k = 2;    
//  rotate_iter(arr, k);
    rotate_byrev(arr, k);
    return 0;
}