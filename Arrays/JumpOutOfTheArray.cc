#include <iostream>
#include <vector>

using namespace std;

// Hackerranck challeneg : Complete the jumpingOnClouds function below.
// Greedy approach

int jumpingOnClouds(vector<int> c) {
   
    int s = c.size();
    int i = 0;
    int n = 0;
    while (i < s)
    {
        if (c[i+2] == 0)
        {
            i+=2;
            n++;
            if (i == s-1) break; 
        }
        else if (c[i+1] == 0){
            i++;
            n++;
            if (i == s-1) break;
        }
    }
    
    return n;
}

int main()
{
    vector<int> v{0,0};
    cout << jumpingOnClouds(v) << endl;
    return 0; 
}