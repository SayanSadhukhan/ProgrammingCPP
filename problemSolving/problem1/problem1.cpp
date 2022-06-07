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
void dispAdj(int v, vector<int> adj[])
{
    cout<<"Displaying adjacency list: "<<endl;
    for (int j = 0; j < v; j++)
    {
        cout<<j<<": ";
        for(auto it: adj[j]){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    
}


void dfs(int node, vector<int> adj[], vector<bool> &vis, stack<int> &st)
{
    vis[node] = true;
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis, st);
        }
    }
    st.push(node);
}


void topoSort(int v, vector<int> adj[])
{
    vector<bool> vis(v,0);
    stack<int> st;
    vector<int> topo;
    for (int i = 0; i < v; i++)
    {
        if(!vis[i]){
            dfs(i, adj, vis, st);
        }
    }
    
    // Taking the elements from the stack and filling a vector with it.
    for (int k = 0; k < v; k++)
    {
        int temp = st.top();
        topo.push_back(temp);
        st.pop();
    }
    
    cout<<"\nThe correct order of the courses will be "<<endl;
    for (auto it2: topo)
    {
        cout<<it2<<" ";
    }
    cout<<endl;
    
}

int main(int argc, char const *argv[]) {
clock_t begin = clock();
file_i_o();

 // Write your code here....
    int v,e; cin>>v>>e;
    vector<int> adj[v];
    for (int i = 0; i < e; i++)
    {
        int u,v; cin>>u>>v;
        adj[v].push_back(u);
    }
    dispAdj(v, adj);   
    topoSort(v,adj);

    #ifndef ONLINE_JUDGE
      clock_t end = clock();
      cout<<"Executed In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}