// Rotting Oranges

#include<bits/stdc++.h>
using namespace std;

#define ll                long long int


void file_i_o()
{
ios_base::sync_with_stdio(0); 
cin.tie(0); 
cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
#endif
}


struct node
{
    int x, y, t;
    node(int _x, int _y, int _t)
    {
        x = _x;
        y = _y;
        t = _t;
    }
};

// Find out minimum time required to get all the oranges rotten
int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int rotten_oranges = 0;
    int oranges = 0;
    queue<node> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2) q.push(node(i, j, 0));
            if (grid[i][j] != 0)  oranges++;
        }
    }
    int ans = 0;
    while (!q.empty())
    {
        int x = q.front().x;
        int y = q.front().y;
        int t = q.front().t;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        q.pop();
        rotten_oranges++;
        ans = t;
        for (int k = 0; k < 4; k++)
        {
            int newX = x + dx[k];
            int newY = y + dy[k];
            if (newX >= 0 and newX < n and newY >= 0 and newY < m)
            {
                if (grid[newX][newY] == 1)
                {
                    grid[newX][newY] = 2;
                    q.push(node(newX, newY, t + 1));
                }
            }
        }
    }
    if(rotten_oranges == oranges) return ans;
    return -1;
}

int main(int argc, char const *argv[]) 
{
clock_t begin = clock();
file_i_o();
// Write your code here....
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n, vector<int> (m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j <m; j++){
            cin>>v[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j <m; j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<orangesRotting(v);

#ifndef ONLINE_JUDGE 
clock_t end = clock();
cout<< "\n\n Executed In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
#endif 
    return 0;
}