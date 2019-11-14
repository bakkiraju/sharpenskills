/*

Given a nested list of integers, return the sum of all integers in the list weighted by their depth. Each element is either an integer, or a list -- whose elements may also be integers or other lists. The weight is defined from bottom up. i.e., the leaf level integers have weight 1, and the root level integers have the largest weight. Given the list [2,[1,1,1,1]] = 8 (four 1's at depth 1, one 2 at depth 2).

[1,4,5,[2,[3],[[[4]]]]] = 17
  
 depth = max_depth - stack_depth
  
*/


#include <iostream>
#include <map>
#include <vector>

using namespace std;

class NestedList{
public:
  int GetInteger();
  bool IsInteger();
  vector<NestedList> GetList();
}

int GetSum(const NestedList& nested_list);

int max_depth=0;

//[1,[2,[3],[[[4]]]]] = 17
map<int, int> dm;


void helper (NestedList &n, int cur_depth)
{
    if (n.IsInteger()) // base case
    {
       int val = n.GetInteger();
       dm[val] = max_depth;       
       return;
    }
    else
    {
       vector<NestedList> v = n.GetList();
       max_depth = max(max_depth, cur_depth);
       for(auto &nl : v)
      {
         helper(nl, cur_depth+1); 
      }
    }
  
  return;  
}

int main() {
  
  NestedList nl;
  
   int sum = 0, cur_depth = 0;
   helper(n1, cur_depth);
   
   for (auto a : dm)
   {
      sum += a*dm[a]; 
   }
  
   cout << sum << endl;
   return 0;
}
