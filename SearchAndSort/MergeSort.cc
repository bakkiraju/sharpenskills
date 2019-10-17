#include <iostream>

using namespace std;

void printArray( int arr[ ], int n, string s)
{

    cout << s << " ";

    for (int i=0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;     
}

void merge(int arr[], int l, int m, int r)
{
    
    int s1 = (m-l) + 1;
    int s2 = (r-m);

    int L[s1];
    int R[s2];

    cout << "Conquer phase:" <<  l << " " << m << " " << r << " " << s1 << " " << s2 << endl;


   for (int i=0; i < s1; i++)
   {
       cout << "copying left:" << endl;
       L[i] = arr[l+i];
   }

   for (int i=0; i < s2; i++)
   {
       cout << "copying right:" << endl;
       R[i] = arr[m+1+i];
   }
 
   printArray(L, s1, "Left:"); 
   printArray(R, s2, "Right:");

   int k = l;
   int i = 0; int j = 0;
   while (i < s1 && j < s2)
   {
       if (L[i] <= R[j])
       {
           arr[k] = L[i];
           i++;
       } 
       else
       {
           arr[k] = R[j];
           j++;
       }
       
       k++;
   }

   while (i < s1)
   {
       arr[k] = L[i];
       k++; i++;     
   }

   while (j < s2)
   {
       arr[k] = R[j];
       k++; j++;
   }

   cout << "Conquering phase done" << endl;
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
       int mid = l + (r-l)/2;

       cout << "Divide phase :" << l << " " << mid << " " << r << endl;

       mergeSort(arr, l, mid);

       mergeSort(arr, mid+1, r);

       merge(arr, l, mid, r);
    }
    cout << "Sub Divide & Conquer done" << endl;
}

int main()
{
    int arr[ ] = {11, 44, 22, 66, 77, 33,55, 99, 88 };
    int n = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr,0, n-1);

    printArray(arr, n, "sorted:");

    return 0;
}