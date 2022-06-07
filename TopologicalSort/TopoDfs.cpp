#include<bits/stdc++.h>
using namespace std;


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
void dispAdjList(int v, vector<int> adj[])
{
    for (int i = 0; i < v; i++)
    {
        cout<<i<<": ";
        for(auto it: adj[i])
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }
    
}


void topoDfs(int node, vector<int> adj[], vector<bool> &visited, stack<int> &st)
{
   visited[node] = true;
   for (auto it: adj[node])
   {
       if(!visited[it])
       topoDfs(it, adj, visited, st);
   }
   st.push(node);
}


vector<int> TopoSort(int v, vector<int> adj[])
{
    stack<int> st;
    vector<int> topo;
    vector<bool> visited(v, 0);
    for (int i = 0; i < v; i++)
    {
        if(!visited[i])
        {
           topoDfs(i, adj, visited, st);
        }
    }
    for(int i = 0; i < v; i++)
    {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}



int main(int argc, char const *argv[]) {
clock_t begin = clock();
file_i_o();

// Write your code here....

    int v, e; cin>> v>>e;
    vector<int> adj[v];
    vector<int> sorted;
    for (int i = 0; i < e ; i++)
    {
        int x, y; cin>>x>>y;
        adj[x].push_back(y);
    }

    // dispAdjList(v, adj);
    sorted = TopoSort(v, adj);
    cout<<"Topological sort: ";
    for(int x: sorted)
    {
        cout<<x<<" ";
    }
    cout<<endl;  


    #ifndef ONLINE_JUDGE
      clock_t end = clock();
      cout<<"Executed In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}