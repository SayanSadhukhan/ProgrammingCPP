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

void disp(int v, vector<int> adj[])
{
    for (int i = 0; i < v; i++)
    {
        cout << i << ": ";
        for (auto it : adj[i])
            cout << it << " ";
        cout << endl;
    }
}


void topoBFS(int v, vector<int> adj[], int indegree[]){
    queue<int> q;
    for(int i = v - 1; i >= 0; i--){
        if(indegree[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int node = q.front();
        cout<<node<<" ";
        q.pop();
        for(auto it: adj[node]){
            if(indegree[it] != 0) indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);

            }
        }
    }
}


void topoHelper(int v, vector<int> arr[])
{
    int indegree[v + 10] = {0};
  
    for (int i = 0; i < v; i++)
    {
        for (auto it : arr[i])
        {
            indegree[it] += 1;
        }
    }
    topoBFS( v,arr, indegree);

    
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int v, e;
    cin >> v >> e;
    vector<int> arr[v + 10];
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[x].push_back(y);
    }

    disp(v, arr);
    topoHelper(v, arr);

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n Executed In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}
