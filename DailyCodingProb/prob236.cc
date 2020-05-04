 // given a list of N points (x1, y1), (x2, y2), ..., (xN, yN) representing a polygon. 
 // You can assume these points are given in order; that is, you can construct the polygon 
 // by connecting point 1 to point 2, point 2 to point 3, and so on, finally looping around to 
 // connect point N to point 1.

#include<iostream>
#include<vector>
#include<limits>

using namespace std;

 bool isInside(vector<pair<int,int>>& v, pair<int,int> p)
 {
     // find the max in x
     int max_x = numeric_limits<int>::min();
     int max_y = numeric_limits<int>::min();
     int min_x = numeric_limits<int>::max();
     int min_y = numeric_limits<int>::max();

     for (auto e : v)
     {
         if (e.first > max_x)
         {
             max_x = e.first;
         }

         if (e.second > max_y)
         {
             max_y = e.second;
         }

         if (e.first < min_x)
         {
             min_x = e.first;
         }

         if (e.second < min_y)
         {
             min_y = e.second;
         }
     }

     if ((min_x < p.first and p.first < max_x) and 
         (min_y < p.second and p.second < max_y))
         {
             return true;
         }
    return false;
 }
 int main()
 {
    vector<pair<int, int>> v{{2,2},{-2,2},{-2,-2},{2,-2}};

    for(auto e : v)
    {
        cout << e.first << " " << e.second << endl;
    }

    bool b = isInside(v, {1,1});

    cout << (b ? "Inside" : "outside") << endl;

    return 0;
 }