
// Shortest Path using BFS
// Graph is having 0 based indexing 
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
   cout<<"Adjacency list is here given by: "<<endl; 
   for (int j = 0; j < v; j++)
   {
       cout<<j<<": ";
       for(auto it: adj[j])
       {
           cout<<it<<" ";
       }
       cout<<endl;
   }
   
}


void bfsShortestPath(int v, vector<int> adj[], int src)
{
    // int dist[v] = {INT_MAX};
    int dist[v];
    for (int i = 0; i < v; i++)
    {
        dist[i] = INT_MAX;
    }
    
    queue<int > q;
    dist[src] = 0;
    q.push(src);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto it: adj[node])
        {
           if (dist[node] + 1 < dist[it])
           {
               dist[it] = 1 + dist[node];
               q.push(it);
           }
           
        }
    }
    cout<<"Shortest path:  "<<endl;
    for(int x: dist)
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
  vector<int> adj[v];
  for (int i = 0; i < e; i++)
  {
      int u, v; cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
  }

//   dispAdjList(v, adj);   // To display the adjacency list
  bfsShortestPath(v, adj, 0);

    #ifndef ONLINE_JUDGE
      clock_t end = clock();
      cout<<"Executed In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}

// Input: 
// 9 11
// 0 1
// 0 3
// 1 3
// 1 2
// 2 6
// 3 4
// 4 5
// 5 6
// 6 7
// 6 8
// 7 8

// Output:
// Adjacency list is here given by: 
// 0: 1 3 
// 1: 0 3 2 
// 2: 1 6 
// 3: 0 1 4 
// 4: 3 5 
// 5: 4 6 
// 6: 2 5 7 8 
// 7: 6 8 
// 8: 6 7 
// 0 1 2 1 2 3 3 4 4 
// Executed In: 1 ms
