


// //=============================================================================================================================================//
// // Shortest path for only two weights 0/1



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

void disp(int v, vector<pair<int, int> > arr[]){
    for(int i = 0; i < v; i++){
        
        cout<<i<<": ";
        for(auto it: arr[i]){
            cout<<"("<<it.first<<", "<<it.second<<") ";
        }
        cout<<endl;
    }
}

// Find the shortest path for each node 

void zeroONeBfs(int v, int src, vector<pair<int, int>> arr[]){
    vector<int> dist(v, 0);
    deque<pair<int,int>> dq;
    for(int i=0; i < v; i++) dist[i] = INT_MAX;

    dist[src] = 0;

    dq.push_front({src, 0});
    while(!dq.empty()){
        int node = dq.front().first;
        int dis = dq.front().second;
        dq.pop_front();

        for(auto it: arr[node]){
            int adjnode = it.first;
            int wt = it.second;
            if(dis + wt < dist[adjnode]){
                dist[adjnode] = dis + wt;
                if(wt > 0 ) dq.push_back({adjnode, wt + dis});
                else dq.push_front({adjnode, wt + dis});
            }
        } 
    }

    for(int i=0; i < v; i++) cout<<i<<"-> "<<dist[i]<<endl;    


}


int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int v, e; 
    cin>>v>>e;
    vector<pair<int, int>> arr[v];
    for(int i = 0; i < e; i++){
        int x, y, w; 
        cin>>x>>y>>w;
        arr[x].push_back({y,w});
        arr[y].push_back({x,w});
    }

    disp(v, arr);
    cout<<"Shortest path from source 1: "<<endl;
    zeroONeBfs(v, 1, arr );

    #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n Executed In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}




// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     float f = (1/9.0);
//     cout<<(f)<<endl;
//     return 0;
// }