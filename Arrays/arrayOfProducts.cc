#include <iostream>
#include <vector>

using namespace std;

// what needs to be calcualted repeatedly at various times
// can be solved using extra space. left, righ array in this 
// case

vector<long> arrayOfArrayProducts(const vector<int>& arr) 
{
  vector<long> res = {};
  vector<long> left(arr.size(),1), right(arr.size(),1);
  
  left[0] = 1;
  for(int i=1; i < arr.size(); i++)
      left[i] = arr[i-1]*left[i-1];
  
  right[arr.size()-1] = 1;
  
  for (int j=arr.size()-2; j >=0 ;j--)
      right[j] = arr[j+1] * right[j+1];
  
  for(int i=0; i < arr.size(); i++)
  {
     long tmp = left[i]*right[i];
     res.push_back(tmp);
  }
   
  return res;
}

int main() {
  vector<int> v={2,3,4,5};
  vector<long> r = arrayOfArrayProducts(v);
  for(auto e=r.begin(); e!= r.end(); e++){
      cout  << *e << " ";
}
  return 0;
}