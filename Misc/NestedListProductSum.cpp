#include <iostream>
#include <any>
#include <vector>

using namespace std;

int productSum(vector<any> &v, int multiplier)
{
    int sum = 0;
    for (auto elem : v)
    {
        if (elem.type() == typeid(vector<any>))
        {
            sum +=productSum(any_cast<vector<any>>elem, multiplier+1);
        }
        else
        {
            sum += any_cast<int>(elem);
        }
        
    }

    return sum*multiplier;
}

int main()
{
    vector<any> v = {1, 2, vector<any>(3), 4, 1};
    cout << productSum(v, 1) << endl;
    return 0;
}