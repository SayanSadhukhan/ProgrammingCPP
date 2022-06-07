// Cycle detection using BFS(Using Kahn's algorithm)

// Code for 0 based indexing of graph
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
void dispAdjLst(int v, vector<int> adj[])
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

bool isCycle(int v, vector<int> adj[])
{
    vector<int> indegree(v, 0);
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
        if(indegree[j] == 0)
        {
            q.push(j);
        }
    }

    int count = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto it: adj[node])
        {
            indegree[it]--;
            if(indegree[it] == 0)
            {
                q.push(it);
            }
        }
        count++;
    }
    
    if(count == v) return false;

    cout<<count<<endl;    
    return true;
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
       adj[u].push_back(v);
   }
   
   dispAdjLst(v, adj);
   cout<<isCycle(v, adj)<<endl;


    #ifndef ONLINE_JUDGE
      clock_t end = clock();
      cout<<"Executed In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}


// Graph with 0 based indexing
// Input: 
// 6 6
// 2 3
// 3 1
// 4 0
// 4 1
// 5 0
// 5 2

// Output:
// 0: 
// 1: 
// 2: 3 
// 3: 1 
// 4: 0 1 
// 5: 0 2 
// 0


//**********************************************************************************************************************************************************************************

// Code for 1 based indexing of graph

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
// void dispAdjLst(int v, vector<int> adj[])
// {
//     for (int i = 1; i <= v; i++)
//     {
//         cout<<i<<": ";
//         for(auto it: adj[i])
//         {
//             cout<<it<<" ";
//         }
//         cout<<endl;
//     }
    
// }

// bool isCycle(int v, vector<int> adj[])
// {
//     vector<int> indegree(v+1, 0);
//     for (int i = 1; i <= v; i++)
//     {
//         for(auto it: adj[i])
//         {
//             indegree[it]++;
//         }
//     }
    

//     queue<int> q;
//     for (int j = 1; j <= v; j++)
//     {
//         if(indegree[j] == 0)
//         {
//             q.push(j);
//         }
//     }

//     int count = 0;
//     while (!q.empty())
//     {
//         int node = q.front();
//         q.pop();
//         for(auto it: adj[node])
//         {
//             indegree[it]--;
//             if(indegree[it] == 0)
//             {
//                 q.push(it);
//             }
//         }
//         count++;
//     }
    
//     if(count == v) return false;

//     // cout<<count<<endl;    
//     return true;
// }


// int main(int argc, char const *argv[]) {
// clock_t begin = clock();
// file_i_o();

//  // Write your code here....
//    int v,e; cin>>v>>e;
//    vector<int> adj[v+1];

//    for (int i = 1; i <= e; i++)
//    {
//        int u,v; cin>>u>>v;
//        adj[u].push_back(v);
//    }
   
//    dispAdjLst(v, adj);
//    cout<<isCycle(v, adj)<<endl;


//     #ifndef ONLINE_JUDGE
//       clock_t end = clock();
//       cout<<"Executed In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
//     #endif
//     return 0;
// }

// Graph with 1 based indexing
// Input:
// 4 4
// 1 2
// 2 3
// 3 4
// 4 2

// Output:
// 1: 2 
// 2: 3 
// 3: 4 
// 4: 2 
// 1

