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

int getFib2(int n)
{
   int cache[n] = {-1};
   cache[0] = 0; cache[1] = 1;

   for(int i=2; i <= n; i++)
   {
      cache[i] = cache[i-1] + cache[i-2];
   }

  return cache[n-1];
}

// 0 1 1 2 3 5 8 13 21 34 55
int main()
{
    cout << getFib(10) << endl;
    cout << getFib2(10) << endl;
    return 0;
}