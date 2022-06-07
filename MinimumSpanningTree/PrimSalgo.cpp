#include<bits/stdc++.h>
using namespace std;

// #define inf    1e18;

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
    cout<<"Adjacency list for the graph is here given by: "<<endl;
    for (int j = 0; j < v; j++)
    {
        cout<<j<<": ";
        for(auto it: adj[j])
        {
            cout<<"{"<<it.first<<","<<it.second<<"} ";
        }
        cout<<endl;
    }
}




void PrimMst(int v, vector<pair<int, int>> adj[], int src)
{
    int key[v], parent[v] ;
    bool mst[v];
    for (int i = 0; i < v; i++)
    {
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;

    }

    key[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0,src});
    while (!pq.empty())
    {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        mst[node] = true;
        for(auto it: adj[node])
        {
            if(it.second < key[it.first])
            {
                key[it.first] = it.second;
                parent[it.first] = node;
                pq.push({key[it.first], it.first});
            }
        }
    }
    for(int j = 1; j < v; j++)
    {
        cout<<parent[j]<<" "<<j<<endl;
    }
    cout<<endl;
}




int main(int argc, char const *argv[]) {
clock_t begin = clock();
file_i_o();

 // Write your code here....
    int v,e; cin>>v>>e;
    vector<pair<int, int>> adj[v];

    for (int i = 0; i < e; i++)
    {
       int u,v,weight; cin>>u>>v>>weight;
       adj[u].push_back(make_pair(v, weight));
       adj[v].push_back(make_pair(u, weight));
//     adj[v].push_back({u, weight});  // Same as the line before
    }
    
    dispAdjList(v, adj);
    cout<<"The minimum spanning tree: "<<endl;
    PrimMst(v, adj, 0);


    #ifndef ONLINE_JUDGE
      clock_t end = clock();
      cout<<"Executed In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}



//******************************************************************************************************************************************************************************************************************

// Input:
// 5 6
// 0 1 2
// 0 3 6
// 1 2 3
// 1 3 8
// 1 4 5
// 2 4 7

// Output:
// Adjacency list for the graph is here given by: 
// 0: {1,2} {3,6} 
// 1: {0,2} {2,3} {3,8} {4,5} 
// 2: {1,3} {4,7} 
// 3: {0,6} {1,8} 
// 4: {1,5} {2,7} 
// The minimum spanning tree: 
// 0 1
// 1 2
// 0 3
// 1 4

//******************************************************************************************************************************************************************************************************************
