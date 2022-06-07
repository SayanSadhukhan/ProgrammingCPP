// Cycle detection in an undirected graph using BFS

// #include<bits/stdc++.h>
// using namespace std;

// void file_i_o()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     #endif

// }
// // define functions...
//   void DisplayAdjMatrix(int v , vector<int> adj[])
//   {
//     for (int i=1; i<=v; i++)
//     {
//       cout<<i<<": ";
//       for(auto it: adj[i])
//       {
//          cout<<it<<" ";
//       }
//       cout<<endl;
//     }
//   }

// // bfsCheckCycle code
// bool bfsCheckCycle(int node, vector<int> &vis, vector<int> adj[])
// {
//   vis[node] = true;
//   queue<pair<int, int>> q;
//   q.push({node, -1});

//   while (!q.empty())
//   {
//     int node = q.front().first;
//     int parentNode = q.front().second;
//     q.pop();

//     for(auto it: adj[node])
//     {
//       if (!vis[it])
//       {
//         vis[it] = true;
//         q.push({it, node});
//       }
//       else if (it != parentNode)
//       {
//           // cout<<it<<" "<<parentNode<<endl;
//           return true;
//       }

//     }

//   }
//   return false;

// }

// // Driver code for checking cycle in a graph using BFS
//   bool isCycle(int v, vector<int> adj[])
//   {
//     vector<int> vis(v+1, 0);
//     for (int i=0; i<=v; i++)
//     {
//       if (!vis[i])
//       {
//         if( bfsCheckCycle(i,vis,adj)) return true;
//       }

//     }
//     return false;

//   }

// int main(int argc, char const *argv[]) {
// clock_t begin = clock();
// file_i_o();

//  // Write your code here....
//     int v, e; cin>> v >>e;
//     vector<int> adj[v+1];
//     for(int i = 1; i <= e; i++ )
//     {
//       int x,y; cin>>x>>y;
//       adj[x].push_back(y);
//       adj[y].push_back(x);
//     }

//     DisplayAdjMatrix(v, adj);

//      cout<<isCycle(v, adj)<<endl;

//     #ifndef ONLINE_JUDGE
//       clock_t end = clock();
//       cout<<"Executed In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
//     #endif
//     return 0;
// }

//***********************************************************************************************************************************************************************************************************************************************************************************************

// Cycle detection using DFS

#include <bits/stdc++.h>
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
  for (int j = 1; j <= v; j++)
  {
    cout << j << ": ";
    for (auto it : adj[j])
    {
      cout << it << " ";
    }
    cout << endl;
  }
}

// DFS code for detecting cycle
bool dfsCheckCycle(int vertex, int parent, vector<int> adj[], vector<bool> &visited)
{
  visited[vertex] = 1; // same as below
  // visited[vertex] = true;
  for (auto it : adj[vertex])
  {
    if (visited[it] == 0)
    {
      if ((dfsCheckCycle(it, vertex, adj, visited)))
        return true;
    }
    else if (visited[it] == 1 && it != parent)
    {
      // cout<<vertex<<" "<<it<<endl;           // To see where it found the
      return true;
    }
  }
  return false;
}

// Driver code for applying DFS to every component in graph
bool isCycle(int v, vector<int> adj[])
{
  vector<bool> visited(v + 1, 0);
  for (int i = 0; i <= v; i++)
  {
    if (visited[i] == 0)
    {
      if (dfsCheckCycle(i, -1, adj, visited))
        return true;
    }
  }
  return false;
}

int main(int argc, char const *argv[])
{
  clock_t begin = clock();
  file_i_o();

  // Write your code here....

  // Constructing the graph
  int v, e;
  cin >> v >> e;

  // Adjacency list
  vector<int> adj[v + 1];
  for (int i = 1; i <= e; i++)
  {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  dispAdjMatrix(v, adj);
  cout << isCycle(v, adj) << endl;
#ifndef ONLINE_JUDGE
  clock_t end = clock();
  cout << "Executed In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
  return 0;
}

// Input1:
// 11 10
// 1 2
// 2 4
// 3 5
// 5 6
// 5 10
// 6 7
// 7 8
// 8 9
// 8 11
// 9 10
//
// Output:
// 1: 2
// 2: 1 4
// 3: 5
// 4: 2
// 5: 3 6 10
// 6: 5 7
// 7: 6 8
// 8: 7 9 11
// 9: 8 10
// 10: 5 9
// 11: 8
// 1

// Input2:
//  8 7
//  1 3
//  3 4
//  2 5
//  5 6
//  5 8
//  6 7
//  7 8
//
// Output:
//  1: 3
//  2: 5
//  3: 1 4
//  4: 3
//  5: 2 6 8
//  6: 5 7
//  7: 6 8
//  8: 5 7
//  1
