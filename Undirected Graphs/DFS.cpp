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

  void DisplayAdjMatrix(int v, vector<int> adj[])
  {
    cout<<"Displaying adjacency matrix..."<<endl;  
    for(int j = 1; j <= v; j++)
    {
        cout<<j<<": ";
        for (int a: adj[j] )
        {
            cout<<a<<" ";
        }
        cout<<endl;
    } 
  }
  
// DFS Traversal
  void DFS_Traversal(int node,  vector<int> adj[], vector<int> &vis, vector<int> &DFS )
  {
    DFS.push_back(node);
    vis[node] = 1;
    for(auto it: adj[node])
    {
        if(!vis[it])
        {
            DFS_Traversal(it, adj, vis, DFS);      // Recursively calling DFS_Traversal function
        }
    }

  }

int main(int argc, char const *argv[]) {
clock_t begin = clock();
file_i_o();

 // Write your code here....
    
    int v,e;
    cin>>v>>e;
    vector<int> adj[v+1];
    for (int i = 1; i <= e; i++)
    {
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }


    DisplayAdjMatrix(v,adj);   // Fuction to display adjacency matrix 
    
    vector<int> vis(v, 0);
    vector<int> DFS;
    for(int i = 1; i <= v; i++)
    {
        if(!vis[i])
        {
            DFS_Traversal(i, adj, vis, DFS);     // Calling DFS_Traversal function
        }
    }

    // Displaying the DFS Traversal
    cout<<"The DFS Traversal of the graph is given by..."<<endl;
    for (auto it: DFS)
    {
        cout<<it<<" ";
    }
    cout<<endl;


    #ifndef ONLINE_JUDGE
      clock_t end = clock();
      cout<<"Executed In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}

// *******************************************************************************************************************************************************************************************************
// Input 1:
// 7 6
// 1 2
// 2 7
// 2 4
// 3 5
// 4 6
// 7 6

// Output:
// Displaying adjacency matrix...
// 1: 2 
// 2: 1 7 4 
// 3: 5 
// 4: 2 6 
// 5: 3 
// 6: 4 7 
// 7: 2 6 
// The DFS Traversal of the graph is given by...
// 1 2 7 6 4 3 5 
// Executed In: 1 ms


// Input 2:
// 7 6
// 1 2
// 2 4
// 2 7
// 3 5
// 4 6
// 7 6

// Output:
// Displaying adjacency matrix...
// 1: 2 
// 2: 1 4 7 
// 3: 5 
// 4: 2 6 
// 5: 3 
// 6: 4 7 
// 7: 2 6 
// The DFS Traversal of the graph is given by...
// 1 2 4 6 7 3 5 
// Executed In: 1 ms
// *******************************************************************************************************************************************************************************************************
