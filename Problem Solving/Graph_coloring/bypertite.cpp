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
////______________________________________________________________________________________________________________________________////
/*
If a graph is a bipertite graph it doesn't have a odd length cycle. A graph having
an odd length cycle is not a bipertite graph.
*/

void dispGraph(int v, vector<int> arr[])
{
    for (int i = 1; i <= v; i++)
    {
        cout << i << ": ";
        for (auto it : arr[i])
        {
            cout << it << " ";
        }
        cout << endl;
    }
}


//===================================== BFS ==========================================================================================//


// bool bfs(int n, vector<int> arr[], vector<int> clr)
// {
//     clr[n] = 1;
//     queue<pair<int, int>> q;
//     q.push({n, clr[n]});
// // Debugging purpose
//     //cout << "Hi" << endl;
//     while (!q.empty())
//     {
//         int node = q.front().first;
//         int colour = q.front().second;
//         q.pop();
//         for (auto it : arr[node])
//         {
//             if (clr[it] == -1)
//             {
//                 clr[it] = !colour;
//                 q.push({it, !colour});
//             }
//             else if (clr[it] != -1 and clr[it] == colour)
//             {
// //     Debugging purpose:                
// //              cout<<"Checked false here...for "<<n<<"...."<<endl;
//                 return false;
//             }
//         }
//     }

// // Debugging purpose
// //    cout << "done" << endl;
//     return true;
// }



// For every component in the graph
// Driver Code (For BFS)
// bool isBipertite(int v, vector<int> arr[])
// {
//     vector<int> clr(v + 1, -1);
//     for (int i = 1; i <= v; i++)
//     {
//         if (clr[i] == -1)
//         {
//             if (bfs(i, arr, clr))
//                 return true;
//         }
//     }
//     return false;
// }


//========================================= DFS ==========================================================================================//

bool dfs(int n, vector<int> adj[], vector<int> clr, bool colour){
    clr[n] = colour;
    for(auto it: adj[n]){
        if(clr[it] == -1){
            if(!dfs(it, adj, clr, !colour)) return false;            
        }
        else if(clr[it] != -1 and clr[it] == colour) return false;
    }
    return true;
}


// For every component of the graph this code will apply DFS
// Driver Code (For DFS)
bool isBipertite(int v, vector<int> arr[])
{
    vector<int> clr(v + 1, -1);
    bool colour = 1;
    for (int i = 1; i <= v; i++)
    {
        if (clr[i] == -1)
        {
            if (!dfs(i, arr, clr, colour))
                return false;
        }
    }
    return true;
}





int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int v, e;
    cin >> v >> e;
    vector<int> arr[v + 10];
    for (int i = 0; i < e; i++)
    {
        int u, m;
        cin >> u >> m;
        arr[u].push_back(m);
        arr[m].push_back(u);
    }

    dispGraph(v, arr);

    if(isBipertite(v, arr))
        cout << "Bipertite" << endl;
    else cout<<"Not Bipertite"<<endl;

    #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n Executed In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}

// #include<iostream>
// using namespace std;

// int main(){
//     int n = 8;
//     cout<<n<<" "<<!n<<endl;
//     return 0;
// }

// Test Cases:
// Input 1:
    // 8 8
    // 1 2
    // 2 3
    // 2 7
    // 3 4
    // 4 5
    // 5 6
    // 5 8
    // 6 7
// Output 1: Bipertite
// Input 2:
// 8 8
// 1 2
// 2 3
// 2 8
// 3 4
// 4 5
// 5 6
// 5 8
// 6 7
// Ouput 2: Not Bipertite
