#include <iostream>
#include <vector>

using namespace std;

/* 
    Number of ways to climb N steps with x possible steps at a time
    where x comes from a set of possible integer values 
*/

int numOfWaysToClimb(int n, vector<int> &v)
{
    int cache[n+1] = {0};

    cache[0] = 1;
    for (int i=1; i < n+1; i++)
    {
       for(int j : v)
       {
          if (i-j >= 0)  cache[i] += cache[i-j];
       }    
    }

    return cache[n];
} 

int main()
{
   int num_steps = 4;

   vector<int> steps{1,2};
 
   int n = numOfWaysToClimb(4,steps);
 
   cout << "Number of steps: " << n << endl;

   return 0;
}
