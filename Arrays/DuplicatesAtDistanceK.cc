/* Find if the array has duplicate items within distance K */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> findDuplicatesAtDistance(vector<int> &v, int size, int dist)
{
    if (dist == 0) { return v;}
  
    unordered_map<int,int> indxMap;
    vector<int> res{};

    for(int i=0; i < size; i++)
    {
        if (indxMap.find(v[i]) != indxMap.end())
        {
            if (i-indxMap[v[i]] <= dist)
            {
                res.push_back(v[i]);
            }
        }
        else
        {
            indxMap[v[i]] = i;
        }
        
    }
    
    return res;
}

int main()
{
    vector<int> array{4,5,6,4,3,2,1,2}; 
    vector<int> res = findDuplicatesAtDistance(array, array.size(), 3);

    for (auto elem : res)
    {
        cout << elem << " ";
    }

    cout << endl;
    return 0;
}