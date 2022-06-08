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

void disp(int v, vector<pair<int, int>> adj[]){
    for(int i = 0; i < v; i++){
        cout<<i<<": ";
        for(auto it: adj[i]){
            cout<<"("<<it.first<<", "<<it.second<<"); ";
        }
        cout<<endl;
    }
}
// Get connected components

void bfs(int n, vector<bool> &vis, vector<pair<int,int>> adj[]){
    vis[n] = 1;
    queue<int> q;
    q.push(n);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it: adj[node]){
            if(!vis[it.first]){
                vis[it.first] = 1;
                q.push(it.first);
            }
        }
    }
}


int checkComponents(int v, vector<pair<int,int>> arr[]){
    int cnt = 0;
    vector<bool> vis(v, 0);
    for(int i = 0; i < v; i++){
            if(!vis[i]){
                cnt++;
                bfs(i, vis, arr);
            }
    }
    return cnt;
}



int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int v, e; 
    cin>>v>>e;
    vector<pair<int,int> > arr[v];
    for(int i = 0; i < e; i++){
        int x,y,w;
        cin>>x>>y>>w;
        arr[x].push_back({y, w});
        arr[y].push_back({x, w});
    }
    
    disp(v, arr);
    cout<<"\n"<<checkComponents(v, arr);
    

    #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n Executed In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}