/* Union-Find algo to catch cycles in Graph */
#include <bits/stdc++.h>

using namespace std;

class Graph
{
    private:
     vector<vector<int>> adj;
     int v, e;
     int find_set (vector<int>&parent, int n)
     {
         if (parent.at(n) == -1)
           return n;

         return find_set(parent, parent.at(n));
     }

     void union_set (vector<int>& parent, int u, int v)
     {
          int xset = find_set(parent, u);
          int yset = find_set(parent, v);

          if (xset != yset)
           parent.at(xset) = yset;
     }

     public:
     Graph(int V, int E) : v(V), e(E) {
           adj.resize(v);
       };

       void addEdge(int src, int dst)
       {
           adj.at(src).push_back(dst);
       }

       void printGraph()
       {
           for (int node=0 ; node < v; ++node)
           {
               cout << node << "--->";
               for (auto e : adj.at(node))
               {
                  cout << e << " ";
               }
               cout << endl;
           }
       }

      bool hasCycle()
      {
         vector<int> parent(v,-1);

         for (int node=0; node < adj.size(); ++node)
         {
             for (auto dst: adj.at(node))
             {
                 int u = find_set(parent, node);
                 int v = find_set(parent, dst);

                 if ( u == v) return true;

                 union_set(parent, u, v);
             }
         }
         return false;
      }
};

int main()
{
    Graph G(3, 3);

    G.addEdge(0, 1);
    G.addEdge(1, 2);
    G.addEdge(0, 2);

    G.printGraph();

    if (G.hasCycle())
    {
        cout << "Has cycle" << endl;
    }

    return 0;
}