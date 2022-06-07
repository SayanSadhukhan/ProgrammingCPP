#include <bits/stdc++.h>
using namespace std;

#define ll long long int

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


// Displaying the graph
void disp_graph(int v, vector<int> arr[])
{
    for (int i = 1; i <= v; i++)
    {
        cout << i << ": ";
        for (int x : arr[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

// Checking cycle using bfs

// bool bfs(int n, vector<int> adj[], vector<bool> visited){
//     visited[n] = true;
//     queue<pair<int,int>> q;
//     q.push({n,-1});
//     while(!q.empty()){
//         int node = q.front().first;
//         int par = q.front().second;
//         q.pop();
//         for(auto it: adj[node]){
//             if(!visited[it]){
//                 visited[it] = true;
//                 q.push({it, node});
//             }
//             else if(visited[it] == true and it != par) return true;
//         }
        
//     }
//     return false;
// }

// bool checkCycle(int v, vector<int> adj[]){
//     vector<bool> visited(v+1, 0);
//     for(int i = 1; i <= v; i++ ){
//         if(!visited[i]){
//             if(bfs(i, adj, visited)) return true;
//         }
//     }
//     return false;
// }


// Checking Cycle using DFS

bool dfs(int n, vector<int> adj[], vector<bool> visited, int parent){
    int node = n;
    int par = parent;
    visited[node] = true;
    
    for(auto it: adj[node]){
        if(!visited[it]){
            visited[it] = true;
            if(dfs(it, adj, visited, node)) return true;
        }
        else if(visited[it] == true and it != par) return true;

    }
    return false;
}
//   NOT NECCESSRAY FOR SINGLE COMPONENT GRAPH
// Driver Code (For applying to every component in graph) 
bool checkCycle(int v, vector<int> adj[]){
    vector<bool> visited(v+1, 0);
    for(int i = 1; i <= v; i++ ){
        if(!visited[i]){
            if(dfs(i, adj, visited, -1)) return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    // Constructing the tree..
    int v, e;
    cin >> v >> e;
    vector<int> arr[v + 1];
    // Getting input properly
    for (int i = 0; i < e; i++)
    {
        int m, n;
        cin >> m >> n;
        arr[m].push_back(n);
        arr[n].push_back(m);
    }

    disp_graph(v, arr);

    if(checkCycle(v,arr)) cout<<"Cycle detected";
    else cout<<"NO Cycle detected";

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n Executed In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

// Input 1:
//  11 10
//  1 2
//  2 4
//  3 5
//  5 6
//  5 10
//  6 7
//  7 8
//  8 9
//  8 11
//  9 10
//
//  Output:
//  1: 2
//  2: 1 4
//  3: 5
//  4: 2
//  5: 3 6 10
//  6: 5 7
//  7: 6 8
//  8: 7 9 11
//  9: 8 10
//  10: 5 9
//  11: 8
//  1  ---> Cycle detected

// Input 2:
//  11 9
//  1 2
//  2 4
//  3 5
//  5 6
//  5 10
//  6 7
//  7 8
//  8 9
//  8 11

//Output 2:
// 1 : 2
// 2 : 1 4 
// 3 : 5 
// 4 : 2 
// 5 : 3 6 10 
// 6 : 5 7 
// 7 : 6 8 
// 8 : 7 9 11 
// 9 : 8 
// 10 : 5 
// 11 : 8 
// NO Cycle detected
