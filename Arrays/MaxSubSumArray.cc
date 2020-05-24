// print sum array max sum and the range
#include <iostream>
#include <vector>
#include<limits>
#include <algorithm>

using namespace std;

int max_subsum(vector<int> &v)
{
    int max_so_far = std::numeric_limits<int>::min();
    int running_sum = v[0];
    int beg = 0;
    int end = 0;
    for(int i=1; i < v.size(); i++)
    {
        running_sum += v[i];
        if (v[i] > running_sum)
        {
            beg = i;
            running_sum = v[i];
        }
        
        if(running_sum > max_so_far)
        {
            max_so_far = running_sum;
            end = i;
        }
    }  

    std::for_each(v.begin()+beg, v.begin()+end+1,[ ](int x){
        cout << x << " ";
    });
    cout << endl;
    return max_so_far;
}

int main()
{
    //vector<int> v{ -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    vector<int> v{ 1, -2, 3};
    cout << max_subsum(v) << endl;
    return 0;
}