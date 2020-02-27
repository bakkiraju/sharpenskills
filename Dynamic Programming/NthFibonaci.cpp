#include <iostream>
#include <unordered_map>

using namespace std;


int helper(int n, unordered_map<int,int> &cache)
{
    if (n == 1 || n == 2)
      return cache[n];
    else
      cache[n] = helper(n-1, cache) + helper(n-2, cache);

    return cache[n];
}


int getFib(int n)
{
   unordered_map<int, int> memoize = {{1,0},{2,1}};    
   return helper(n, memoize);
}


int main()
{
    cout << getFib(10) << endl;
    return 0;
}