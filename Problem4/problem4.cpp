#include <bits/stdc++.h>
using namespace std;

#define ll long long int

void file_i_o()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
{
    int n = maze.size();
    int m = maze[0].size();

    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    vis[start[0]][start[1]] = 1;
    queue<pair<int, int>> q;
    q.push({start[0], start[1]});

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == destination[0] and y == destination[1])
            return true;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int newX = x;
            int newY = y;
            while (newX >= 0 and newX < n and newY >= 0 and newY < m and maze[newX][newY] == 0)
            {
                newX += dx[i];
                newY += dy[i];
            }
            newX -= dx[i];
            newY -= dy[i];

            if (vis[newX][newY] == 0)
            {
                vis[newX][newY] = 1;
                q.push({newX, newY});
            }
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << v[i][j];
        }
        cout << endl;
    }
    cout << endl;
    vector<int> start(2, 0);
    cin >> start[0] >> start[1];
    vector<int> en(2, 0);
    cin >> en[0] >> en[1];
    cout << start[0] << ", " << start[1] << endl;
    cout << en[0] << ", " << en[1] << endl;
    cout << hasPath(v, start, en);

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n Executed In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}