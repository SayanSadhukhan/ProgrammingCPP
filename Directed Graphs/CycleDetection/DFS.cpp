// Cycle detection using DFS
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
void dispAdjMatrix(int v, vector<int> adj[])
{
    for(int j = 1; j <= v; j++ )
    {
        cout<<j<<": ";
        for(auto it: adj[j])
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }
}



bool dfsCheckCycle(int node, vector<int> adj[], vector<bool> &visited, vector<bool> &dfsvis)
{
    visited[node] = 1;
    dfsvis[node] = 1;
    for(auto it: adj[node]){
        if(!visited[it])
        {
           if( dfsCheckCycle(it, adj, visited, dfsvis)) return true;
        }
        else if(dfsvis[it])
        {
            return true;
        }
    }
    dfsvis[node] = 0;
    return false;
}





bool isCycle(int v, vector<int> adj[])
{
    vector<bool> visited(v+1, 0);
    vector<bool> dfsvis(v+1, 0);
    for(int i = 1; i<= v; i++)
    {
        if (!visited[i]){
            if(dfsCheckCycle(i, adj, visited, dfsvis)) return true;
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

    for(int i = 1; i<= e; i++)
    {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
    } 
    
    dispAdjMatrix(v, adj);
    cout<<isCycle(v, adj)<<endl;

    #ifndef ONLINE_JUDGE
      clock_t end = clock();
      cout<<"Executed In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}

//********************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************
//
//
// Input1:      Output: NO
// 9 10
// 1 2
// 2 3
// 3 4
// 3 6
// 4 5
// 6 5
// 7 2
// 7 8
// 9 7
// 9 8




// Input2:      Output: YES
// 9 10
// 1 2
// 2 3
// 3 4
// 3 6
// 4 5
// 6 5
// 7 2
// 7 8
// 8 9
// 9 7







//********************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************