#include <iostream>
#include <vector>

using namespace std;

int countIslands(vector<vector<int> &mat)
{
    bool visited[mat.size()][mat[0].size()];
    memset(visited, 0, sizeof(visited));
    
}

int main()
{

   vector<vector<int>> mat {
       {1, 1, 0, 0, 0},
       {0, 1, 0, 0, 1},
       {1, 0, 0, 1, 1},
       {0, 0, 0 ,0, 0},
       {1, 0, 1, 0 ,1}
   };

//    for (auto i=0; i < mat.size(); i++)  
//    {
//      for (auto j=0; j < mat[0].size(); j++)
//        cout << mat[i][j] << " ";
            
//        cout << endl;
//    }

    countIslands(mat);

   return 0;
}