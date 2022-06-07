/// BFS traversal algorithm
// Undirected Graph

#include<bits/stdc++.h>
using namespace std;

#define ll                long long int
vector<int> adj[100005];
vector<bool> vis;

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

void bfs(int node){
    queue<int> q;
    vis[node] = 1;
    q.push(node);
    while(!q.empty()){
        int v = q.front();
        cout<<v<<" ";
        q.pop();
        for(auto it: adj[v]){
            if(vis[it] == 0){
                vis[it] = 1;
                q.push(it);
            }
        }
    }

}


int main(int argc, char const *argv[]) 
{
clock_t begin = clock();
file_i_o();
// Write your code here....

// Taking inputs
    int n,m; cin>>n>>m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
// Initializing visited array    
    vis.resize(n + 1);
    for(int i = 0; i <= n; i++){
        vis[i] = 0;
    }
// BFS traversal
    for(int j = 1; j<= m;j++ ){
        if(vis[j] == 0) bfs(j);
    }
#ifndef ONLINE_JUDGE 
clock_t end = clock();
cout<< "\n\n Executed In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
#endif 
    return 0;
}