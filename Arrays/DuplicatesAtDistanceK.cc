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

#include <unordered_set>
vector<int> findDuplicatesWithinDistanceK(vector<int> array, int k)
{
    unordered_set<int> s;
    vector<int> res{};

    for(int i=0; i < array.size(); i++)
    {
        if (s.find(array[i]) != s.end())
        {
            res.push_back(array[i]);
        }

        auto r = s.insert(array[i]);
        
        if (s.size() > k)
          s.erase(array[i-k]);
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
   
    res = findDuplicatesWithinDistanceK({5,6,8,2,4,6,9}, 4);

    for (auto elem : res)
    {
        cout << elem << " ";
    }

    cout << endl;
   
    return 0;
}