// Two sorted array
// Pick elements from each and place them in right arrays so that all less value
// numbers are in one array and all greater value numbers are in another array

#include <iostream>
#include <vector>

using namespace std;

void placeInCorrectArray(vector<int> &arr1, vector<int>  &arr2)
{
    vector<int> res(arr1.size() + arr2.size());
  
    int i = 0; 
    int j = 0;
    int k = 0;

    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] < arr2[j])
        {
            res[k] = arr1[i]; i++; k++;
        }

        if (arr1[i] > arr2[j])
        {
            res[k] = arr2[j]; j++; k++;
        }
    }

    for (; i < arr1.size(); i++)
    {
        res[k] = arr1[i]; k++;
    }

    for (; j < arr2.size(); j++)
    {
        res[k] = arr1[j]; k++;
    }

    for (auto elem : res)
    {
        cout << elem << " ";
    }
    cout << endl;

    k = 0;
    for (int l = 0; l < arr1.size(); l++)
    {
         arr1[l] = res[k++];
    }

    for (int l = 0; l < arr2.size(); l++)
    {
        arr2[l] = res[k++];
    }
}

int main()
{
   vector<int> arr1{1, 4, 7, 8, 10};
   vector<int> arr2{2, 3, 9}; 

   placeInCorrectArray(arr1, arr2);

   for (auto elem : arr1)
     cout << elem <<  " ";

   cout << endl;

   for (auto elem : arr2)
     cout << elem <<  " ";

   return 0;
}