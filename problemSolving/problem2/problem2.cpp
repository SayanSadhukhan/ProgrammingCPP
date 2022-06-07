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

void disp(int v, vector<int> adj[])
{
    for (int i = 1; i <= v; i++)
    {
        cout<<i<<": ";
        for(auto it: adj[i])
        cout<<it<<" ";
        cout<<endl;
    }
    
}

bool dfs(int node, vector<int> adj[], int color[])
{ 
    if (color[node] == -1)  color[node] = 1;
    // int parent = node;
    for(auto it: adj[node]){
        if (color[it] == -1){
            color[it] = 1 - color[node];
            if (!dfs(it, adj, color)) return false;
        }
        else if (color[it] == color[node]) return false;
    }
    return true;
}

bool isBipertite(int v, vector<int> adj[], int color[])
{
   for(int i=1; i<=v; i++){
      if(color[i] == -1)
      {
          if(!dfs(i, adj, color)) return false;
      }
   }
   return true;
}

void showGrp(int v, vector<int> adj[], int color[])
{
    if(isBipertite(v, adj, color)){
    pair<vector<int>, vector<int>> group;
        for(int j = 1; j<= v; j++){
            if(color[j] == 0) group.first.push_back(j);
            else if(color[j] == 1) group.second.push_back(j);
        }
    cout<<"first group"<<endl;
    for(auto it: group.first)
    cout<<it<<" ";
    cout<<"\nsecond group"<<endl;
    for(auto it2: group.second)
    cout<<it2<<" ";
    cout<<endl;
    }
    else cout<<"Cannot be splited in two group"<<endl;
}


int main(int argc, char const *argv[]) {
clock_t begin = clock();
file_i_o();

 // Write your code here....
    int v,e; cin>>v>>e;
    vector<int> adj[v+1];
    int  color[v+1];
    memset(color, -1, sizeof color);
    for (int i = 1; i <= e; i++)
    {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
     
    disp(v,adj);
    showGrp(v,adj,color);
    

    #ifndef ONLINE_JUDGE
      clock_t end = clock();
      cout<<"Executed In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}