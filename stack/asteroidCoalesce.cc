/* Leet code 753

*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> asteroidCollision(vector<int> &ast)
{
    vector<int> res;

    for (int a : ast)
    {
        // if moving right keep adding
        if (a > 0)
        {
            res.push_back(a);
        }
        else // if moving left
        {
            // merge all lower value asteroids moving in opposite dir
            while (not res.empty() && res.back() > 0 && res.back() < abs(a))
            {
                res.pop_back();
            }
            // if equal but opposite, pop out the equal
            if (not res.empty() && res.back() == abs(a))
            {
                res.pop_back();
            }
            else if (not res.empty() && res.back() > abs(a))
            {
                continue;
            }
            else 
            {
                res.push_back(a);
            }
        }
    }
        
    return res;     
}

int main()
{
    vector<int> asteroids {5,10,-5};
    vector<int> res = asteroidCollision(asteroids);

    for (int i : res)
    {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}