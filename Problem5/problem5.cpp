#include <bits/stdc++.h>
using namespace std;

#define ll long long int
vector<int> arr[100005];

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


bool dfsDetectCycle(int node, int par, vector<bool> &vis)
{
    vis[node] = 1;
    for (auto it : arr[node])
    {
        if (vis[it] == true && it != par)
        {
            cout << node << "," << it << endl;
            return true;
        }
        else if (!vis[it])
        {
            if (dfsDetectCycle(it, node, vis))
            {
                cout << node << "," << it << endl;
                return true;
            }
        }
    }
    return false;
}

// Check cycle
void checkCycle(int node, int par, vector<bool> &vis, int n){
    int i = 0;
    for (i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (dfsDetectCycle(i, par, vis))
            {
                cout << "Cycle found at node " << i;
                break;
            }
        }
    }
    if (i == n + 1)
        cout << "Cycle not found" << endl;
}


int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    cout << "Hello Suckers!" << endl;
    // Display adjacent matrix
    for (int j = 1; j < n + 1; j++)
    {
        cout << j << " --> ";
        for (auto it : arr[j])
        {
            cout << it << ", ";
        }
        cout << endl;
    }
    vector<bool> vis(n+1, 0);
    checkCycle(1,0, vis, n);
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n Executed In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}