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
// ==========================================================================================================//
//                              Floyd Warshell Algorithm
//              TC: O(n^3)
//    Find out shortest distance from each node to every other node in the graph
// Display the graph
void dispGraph(int n, vector<pair<int, int>> arr[]){
    for(int i = 0; i < n; i++){
        cout<<i<<": ";
        for(pair<int ,int> p: arr[i]){
            cout<<"("<<p.first<<", "<<p.second<<") ";
        }
        cout<<endl;
    }
}

// Applying Floyd Warshall
void floydWarshall(int n, vector<pair<int, int>> adj[]){
    
// Initializing the distance matrix
    vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
    for(int i = 0; i <n; i++){
        dist[i][i] = 0;
    }

    for(int i = 0; i < n; i++){
        for(pair<int, int> p : adj[i] ){
            int x = i;
            int y = p.first;
            int w = p.second;
            dist[x][y] = w;
        }
    }

// Displaying dist matrix
    // cout<<"\n";
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout<<dist[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;


// Including every vertex from k = 0 to k = n - 1 to get shortest path
    for(int k = 0; k < n; k++ ){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dist[i][k] != INT_MAX and dist[k][j] != INT_MAX){
                    dist[i][j] = min(dist[i][j], (dist[i][k] + dist[k][j]));
                }
            }
        }
    }

// Displaying the shortest path matrix
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;



}


int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int n, e;
    cin>>n>>e;
    vector<pair<int, int>> arr[n];
    for(int i = 0; i < e; i++){
        int x,y, w;
        cin>>x>>y>>w;
        arr[x].push_back({y,w});
        arr[y].push_back({x,w});
    }

    dispGraph(n, arr);
    floydWarshall(n, arr);

    #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n Executed In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}
