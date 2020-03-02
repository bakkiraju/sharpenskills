#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int rows[] = {-1, 0, 0, 1};
int cols[] = {0, -1, 1, 0};

int shortestPathLen(vector<vector<int>> &grid, int sr, int sc, int tr, int tc)
{
    if (grid.size() == 0)
        return -1;

    if (sr == tr && sc == tc)
        return 0;

    int len = 0;
    int visit[grid.size()][grid[0].size()];

    cout << grid.size() << ":" << grid[0].size() << endl;

    memset(visit, 0, grid.size() * grid[0].size() * sizeof(int));

    queue<pair<int, int>> q;

    q.push({sr, sc});
    visit[sr][sc] = 1;

    for (int r = 0; r < grid.size(); r++)
    {
        for (int c = 0; c < grid[0].size(); c++)
        {
            cout << visit[r][c] << " ";
        }

        cout << endl;
    }

    while (not q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        int x = p.first;
        int y = p.second;

        if (x == tr && y == tc)
        {
            return visit[tr][tc];
        }

        for (int i = 0; i < 4; i++)
        {
            int nr = x + rows[i];
            int nc = y + cols[i];

            bool rInRange = (nr >= 0 && nr < grid.size());
            bool cInRange = (nc >= 0 && nc < grid[0].size());

            if (rInRange && cInRange && grid[nr][nc] && visit[nr][nc] == 0)
            {
                cout << nr << ":" << nc << endl;
                q.push({nr, nc});
                visit[nr][nc] = visit[x][y] + 1;

                for (int r = 0; r < grid.size(); r++)
                {
                    for (int c = 0; c < grid[0].size(); c++)
                    {
                        cout << visit[r][c] << " ";
                    }
                    cout << endl;
                }
            }
        }
    }
    return visit[tr][tc];
}

int main()
{
    vector<vector<int>> grid = {
        {1, 1, 1, 1},
        {1, 0, 0, 1},
        {1, 1, 1, 1}};

    int len = shortestPathLen(grid, 0, 0, 2, 0);

    cout << "Length:" << len << endl;

    return 0;
}