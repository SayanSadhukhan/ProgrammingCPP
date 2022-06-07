#include<bits/stdc++.h>
using namespace std;

#define  inf   1e9;


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
// define functions...
void display(int v, vector<int> adj[])
{
    for (int i = 0; i < v; i++){
        cout<<i<<": ";
        for(auto it: adj[i]){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    
}

bool dfsDetect(int node,int parent, vector<int> adj[], vector<bool> &vis) 
{
    vis[node] = true;
    for(auto it: adj[node]){
        if(!vis[it]){
            if (dfsDetect(it, node, adj, vis)) return true;
        }
        else if( it != parent) return true;
    
    }
    return false;
} 


bool isCycle(int v, vector<int> adj[])
{
    vector<bool> vis(v+1, 0);
    for (int j = 1;  j <= v; j++)
    {
       if(!vis[j]){
           if(dfsDetect(j, -1, adj, vis)) return true;
       }
    }
    return false;
    
}


int main(int argc, char const *argv[]) {
clock_t begin = clock();
file_i_o();

 // Write your code here....
    
    int v, e; cin>>v>>e;
    vector<int> adj[v+1];
    for (int i = 0; i < e; i++)
    {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    display(v, adj);
    cout<<"\n"; 
    if (isCycle(v, adj)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    

    #ifndef ONLINE_JUDGE
      clock_t end = clock();
      cout<<"Executed In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}


// 1(1) -- 3(1) -- 


