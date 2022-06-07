// Code for determining bipertite graph
// Graph coloring

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
// // Display the adjacency graph
// void dispAdjMatrix(int v, vector<int> adj[])
// {

//     for (int i = 1; i<= v; i++)
//     {
//         cout<<i<<": ";
//         for(auto it: adj[i])
//         {
//             cout<<it<<" ";
//         }
//         cout<<endl;
//     }
// }



// bool bipertiteBfs(int node, vector<int> adj[], int color[])
// {
//     queue<int>  q;
//     q.push(node);
//     color[node] = 1;
//     while (!q.empty())
//     {
//         int vertex = q.front();
//         q.pop();
//         for(auto it: adj[vertex])
//         {
//             if(color[it] == -1)
//             {
//                 color[it] = 1 - color[vertex];
//                 q.push(it);
//             }
//             else if(color[it] == color[vertex]) return false;
//         }
//     }
//     return true;
// }



// bool isBipertite(int v, vector<int> adj[])
// {
//     int color[v+1];
//     memset(color, -1, sizeof color);
//     for (int i = 1; i <= v; i++)
//     {
//         if(color[i] == -1){
//             if(!bipertiteBfs(i, adj, color)) return false;
//         }
//     }
//     return true;
// }
    


// int main(int argc, char const *argv[]) {
// clock_t begin = clock();
// file_i_o();

//  // Write your code here....
//     int v, e; cin>>v>>e;
//     vector<int> adj[v+1];
//     for (int i = 1; i <= e; i++)
//     {
//         int x,y; cin>>x>>y;
//         adj[x].push_back(y);
//         adj[y].push_back(x);
//     }
    
//     // dispAdjMatrix(v, adj);           // Function to display the adjacency matrix
//     if(isBipertite(v, adj)) cout<<"YES"<<endl;
//     else cout<<"NO"<<endl;

//     #ifndef ONLINE_JUDGE
//       clock_t end = clock();
//       cout<<"Executed In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
//     #endif
//     return 0;
// }

//***********************************************************************************************************************************************************************************************************************************************************************************************************

// // Input1:            Output: NO
// 8 8                   
// 1 2
// 2 3
// 2 8
// 3 4
// 4 5
// 5 6
// 5 8
// 6 7



// Input2:          Outpur: YES
// 8 8
// 1 2
// 2 3
// 2 7
// 3 4
// 4 5
// 5 6
// 5 8
// 6 7

//***********************************************************************************************************************************************************************************************************************************************************************************************************


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
  void DispAdjMatrix(int v, vector<int> adj[])
  {
      for (int i = 1; i <= v; i++)
      {
          cout<<i<<": ";
          for(auto it: adj[i])
          {
              cout<<it<<" ";
          }
          cout<<endl;
      }
      
  }




  bool bipertiteDfs(int node, vector<int> adj[], int color[])
  {
    if(color[node] == -1)  color[node] = 1;
    int parent = node;
    for(auto it: adj[node])
    {
        if(color[it] == -1)
        {
            color[it] = 1 - color[parent];
            if(!bipertiteDfs(it, adj, color)) return false;
        }
        else if(color[it] == color[parent])
        {
            return false;
        }
    }
    return true;
  }

// Driver Code (Applying DFS to every component of graph)

   bool isBipertite(int v, vector<int> adj[])
   {
      int color[v+1];
      memset(color, -1, sizeof color);
      for (int i = 1; i <= v; i++)
      {
          if(color[i] == -1)
          {
            if(!bipertiteDfs(i ,adj, color)) return false;
          }
      }
      return true;
   }



int main(int argc, char const *argv[]) {
clock_t begin = clock();
file_i_o();

 // Write your code here....
    int v, e; cin>>v>>e;
    vector<int> adj[v+1];

    for (int i = 1; i <= e; i++)
    {
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    DispAdjMatrix(v, adj);
    cout<<isBipertite(v, adj)<<endl;



    #ifndef ONLINE_JUDGE
      clock_t end = clock();
      cout<<"Executed In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}