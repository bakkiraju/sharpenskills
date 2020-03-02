#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> sortKMessedArray( const vector<int>& arr, int k ) 
{
   priority_queue<int, vector<int>, greater<int>> pq;
   vector<int> res;
  
   for(int i=0; i <= k+1; i++)
   {
     pq.push(arr[i]);
   }

  for(int j=k+2; j < arr.size(); j++)
  {
     res.push_back(pq.top());
     pq.pop();
     pq.push(arr[j]);
  }
  
  while (pq.empty() == false)
  {
     res.push_back(pq.top());
     pq.pop();
  }
  
  return res;
}

int main() {
  vector<int> v = {1,4,5,3,2};
  vector<int> res = sortKMessedArray(v, 2);
 
  for(auto elem : res)
  { 
    cout << elem << " " ;
  } 
  return 0;
}