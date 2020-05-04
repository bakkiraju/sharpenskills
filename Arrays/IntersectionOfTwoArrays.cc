// Leet code 350 : Intersection Of Two Arrays
#include <vector>
#include <set>
#include <iostream>

using namespace std;

vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    multiset<int> s;

    for (auto e : nums1)
    {
        s.insert(e);
    }

    vector<int> res{};

    for (auto e : nums2)
    {
        auto it = s.find(e);
        if (it != s.end())
        {
            s.erase(it); 
            res.push_back(e);
        }
    }

    return res;
}

int main()
{
    vector<int> nums1{2 , 2};
    vector<int> nums2{1, 2, 2, 1};

    vector<int> v= intersect(nums1, nums2);
    
    for(auto e: v)
    {
        cout << e << " ";
    } 

    cout << endl;

    return 0;
}