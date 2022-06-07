// Code for shortest path using DFS 
// 0 based indexing
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
void dispAdjList(int v, vector<pair<int, int>> adj[])
{
   cout<<"Adjacency list is here given by: "<<endl; 
   for (int j = 0; j < v; j++)
   {
       cout<<j<<": ";
       for(auto it: adj[j])
       {
           cout<<"{"<<it.first<<","<< it.second<<"}  " ;
       }
       cout<<endl;
   }
   
}

void dfsTopoSort(int node, vector<pair<int, int>> adj[],vector<bool> &visited, stack<int> &st)
{
    visited[node] = 1;
    for(auto it: adj[node])
    {
        if(!visited[it.first])
        {
            dfsTopoSort(it.first, adj, visited, st);
        }
    }
    st.push(node);

}

void shortestPath(int v,int src, vector<pair<int, int>> adj[])
{
    vector<bool> visited(v, 0);
    stack<int> st;
    for (int i = 0; i < v; i++)
    {   
        if(!visited[i])
        dfsTopoSort(i, adj,visited, st);
    }
        int dist[v];
        for(int j= 0; j<v; j++)
        {
            dist[j] = INT_MAX;
        }
        dist[src] = 0;
        
        while(!st.empty()){
            
            int vertex = st.top();
            st.pop();
            for(auto it: adj[vertex])
            {
               if(dist[vertex] != INT_MAX)
            dist[it.first] = min(dist[it.first] , dist[vertex] + it.second);
            }
        }

        for (int x: dist)
        {
            cout<<x<<" ";
        }
        cout<<endl;
}


int main(int argc, char const *argv[]) {
clock_t begin = clock();
file_i_o();

 // Write your code here....
   int v, e; cin>>v>>e;
  vector<pair<int, int>> adj[v];              // Adjacency list
  for (int i = 0; i < e; i++)         
  {
      int u, v, wt; cin>>u>>v>>wt;            // Taking graph input
      adj[u].push_back({v, wt});
  }
  dispAdjList(v,adj);
  
  cout<<"Shortest path is hereby given: "<<endl;
  shortestPath(v, 0, adj);

    #ifndef ONLINE_JUDGE
      clock_t end = clock();
      cout<<"Executed In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}



//***********************************************************************************************************************************************************************************************************
// Input:
// 6 7
// 0 1 2
// 0 4 1
// 1 2 3
// 2 3 6
// 4 2 2
// 4 5 4
// 5 3 1

// Output:
// Adjacency list is here given by: 
// 0: {1,2}  {4,1}  
// 1: {2,3}  
// 2: {3,6}  
// 3: 
// 4: {2,2}  {5,4}  
// 5: {3,1}  
// Shortest path is hereby given: 
// 0 2 3 6 1 5 
// Executed In: 0 ms

//***********************************************************************************************************************************************************************************************************