/* Depth first search of a non weighted Graph */
#include <bits/stdc++.h>
using namespace std;

#define V 6

struct Edge {
    int src, dst;
};

void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj.at(u).push_back(v);
}

void constructGraph(vector<vector<int>> &adj, vector<Edge> &edges)
{

    for(Edge e : edges)
    {
        addEdge(adj, e.src, e.dst);
    }
}

void printGraph(vector<vector<int>> &adj)
{
    for (int i=0; i < adj.size(); i++)
    {
        cout << i << "---->";

       for (auto e : adj[i])
        {
            std::cout << e << " ";
        }
       cout << endl;
    }
}

vector<int> DFS(vector<vector<int>> &adj)
{
    stack<int> s;
    vector<int> result{};
    bool visited[adj.size()]={0};

    for(int i=0; i < adj.size(); i++)
    {
        if (not visited[i])
        {
            visited[i] = 1;
            s.push(i);

            while(not s.empty())
            {
                int k = s.top();
                s.pop();
                result.push_back(k);

                for (auto node : adj[k])
                {
                    if (not visited[node])
                    {
                        visited[node] = 1;
                        s.push(node);
                    }
                }
            }
        }
    }

    return result;
}

vector<int> BFS(vector<vector<int>> &adj)
{
    queue<int> s;
    vector<int> result{};
    bool visited[adj.size()]={0};

    for(int i=0; i < adj.size(); i++)
    {
        if (not visited[i])
        {
            visited[i] = 1;
            s.push(i);

            while(not s.empty())
            {
                int k = s.front();
                s.pop();
                result.push_back(k);

                for (auto node : adj[k])
                {
                    if (not visited[node])
                    {
                        visited[node] = 1;
                        s.push(node);
                    }
                }
            }
        }
    }

    return result;
}

int main()
{
    vector<vector<int>> adj(V);

//    vector<Edge> edges =
// 	{
// 		{ 0, 1 }, {0,2}, { 1, 2 }, {2,0},{2,3},{3,3}
// 	};

    // vector<Edge> edges =
	// {
	// 	{ 1, 0 }, { 0, 2 }, { 2, 1 }, { 0, 3 },{ 1, 4 }
	// };

    vector<Edge> edges =
	{
		{ 0, 1 }, { 0, 2 }, { 1, 3 }, { 1, 4 },{ 2, 5 }
	};
   constructGraph(adj, edges);

   printGraph(adj);

   vector<int> v = DFS(adj);

   for (auto k : v)
   {
       cout << k << endl;
   }

  cout << endl;

   vector<int> v1 = BFS(adj);

   for (auto k : v1)
   {
       cout << k << endl;
   }

   return 0;
}