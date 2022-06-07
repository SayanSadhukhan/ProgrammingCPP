#include<bits/stdc++.h>
using namespace std;

#define ll                long long int


void file_i_o()
{
ios_base::sync_with_stdio(0); 
cin.tie(0); 
cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
#endif
}
// Cycle check of a Directed Graph using DFS



void dispGraph(int v, vector<int> adj[]){
    for(int i = 1; i <= v;i++){
        cout<<i<<": ";
        for(auto it: adj[i]){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}
// DFS process
bool dfsDirect(int n, vector<int> adj[], vector<bool> vis, vector<bool> visRt){
    vis[n] = true;
    visRt[n] = true;
    for(auto it: adj[n]){
        if(!vis[it]){
            vis[it] = true;
            if(dfsDirect(it, adj, vis, visRt)) return true;
            
        }
        else if (vis[it] == true and visRt[it] == true)
            return true;
    }
    visRt[n] = 0;
    return false;
}



// Applying DFS to every component in the graph
// Driver Code
bool check_Dir_Cycle(int v, vector<int> adj[]){
    vector<bool> vis(v+1, 0);
    vector<bool> visRt(v+1, 0);
    for(int i = 1; i <= v; i++){
        if(!vis[i] == true){
            if(dfsDirect(i, adj, vis, visRt)) return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[]) 
{
clock_t begin = clock();
file_i_o();
// Write your code here....
    int v,e; 
    cin>>v>>e;


// Constructing the graph
    vector<int> adj[v+1];
    for(int i = 0; i < e; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);

    }

//Displaying the graph
    dispGraph(v,adj);

//Calling the Check cylce funciton
    if(check_Dir_Cycle(v,adj)) cout<<"Cycle Detected";
    else cout<<"No Cycle Detected"; 

#ifndef ONLINE_JUDGE 
clock_t end = clock();
cout<< "\n\n Executed In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
#endif 
    return 0;
}