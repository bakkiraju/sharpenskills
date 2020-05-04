#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

static int __ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

class Solution {
public:
  int singleNumber(vector<int>& nums) {
    return accumulate(nums.begin(), nums.end(),0, [](auto a, auto b){
      return a ^ b;
    });
  }
};

int main()
{
    Solution s;
    vector<int> v = {1,2,2,3,3,1,5};
    int single = s.singleNumber(v);
    cout << single << endl;
    return 0;
}