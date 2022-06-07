// Topological sort using BFS
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



vector<int> topoBfs(int v, vector<int> adj[])
{
   vector<int> indegree(v, 0);
   vector<int> topoSort;

   for (int i = 0; i < v; i++)
   {
       for(auto it: adj[i])
       {
          indegree[it]++;
       }
   }
   
   queue<int> q;

   for (int j = 0; j < v; j++)
   {
       if (indegree[j] == 0)
       {
           q.push(j);
       }
       
   }
   while (!q.empty())
   {
       int node = q.front();
       q.pop();
       topoSort.push_back(node);
       for(auto it: adj[node])
       {
           indegree[it]--;
           if (indegree[it] == 0)
           {
               q.push(it);
           }
           
       }
   }
   return topoSort;
    
   
}


int main(int argc, char const *argv[]) {
clock_t begin = clock();
file_i_o();

 // Write your code here....
  int v, e; cin>>v>>e;
  vector<int> adj[v];
  vector<int> sorted;
  for(int i = 0; i < e; i++)
  {
      int x, y; cin>>x>>y;
      adj[x].push_back(y);
  }


  dispAdjList(v, adj);
  sorted = topoBfs(v, adj);
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

// INPUT:
// 6 6
// 2 3
// 3 1
// 4 0
// 4 1
// 5 0
// 5 2

// OUTPUT:
// 0: 
// 1: 
// 2: 3 
// 3: 1 
// 4: 0 1 
// 5: 0 2 
// 4 5 0 2 3 1 
// Executed In: 0 ms


