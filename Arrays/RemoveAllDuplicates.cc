#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int> &nums)
{
  int n = nums.size();

  int p1 = 0, p2 = 0;

  vector<int> &a = nums;

  while (p2 < n)
  {
    while ((a[p1] == a[p2]) && (p2 < n))
    {
      p2++;
    }
    p1++;
    a[p1] = a[p2];
  }

  return p1;
}

int main()
{
  vector<int> v{0, 0, 1, 1, 1, 1, 2, 2, 3, 3, 4};
  int j = removeDuplicates(v);
  for (int i = 0; i < j; i++)
    cout << v[i] << " ";

  cout << endl;

  return 0;
}