#include<bits/stdc++.h>
using namespace std;

#define  inf   1e18;


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
void display(int v, vector<int> adj[])
{
    for(int i=1; i<=v; i++)
    {
        cout<<i<<": ";
        for(auto it: adj[i])
        cout<<it<<" ";
    cout<<endl;
    }
}



bool bfsDetect(int node, vector<int> adj[], vector<bool> &visited)
{
    visited[node] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(node, -1));
    while (!q.empty())
    {
        int vertex = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto it: adj[vertex])
        {
            if(!visited[it]){
                visited[it] = true;
                q.push({it, vertex});
            }
            else if(it != parent){ 
                // cout<<it<<" "<<parent<<endl;
                return true;
            }
        }   
    }
    return false;

}


bool isCycle(int v, vector<int> adj[])
{
    vector<bool> visited(v+1, 0);
    for (int i = 1; i <= v; i++){
        if(!visited[i])
        {
            if (bfsDetect(i,adj,visited))  return true;
        }
    }
    return false;
    
}


int main(int argc, char const *argv[]) {
clock_t begin = clock();
file_i_o();

 // Write your code here....
    int v, e; cin>>v>>e;
    vector<int> adj[v+1];
    for(int i = 1; i<=e; i++)
    {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }  
    display(v, adj);
    cout<<endl;
    if (isCycle(v, adj)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;


    #ifndef ONLINE_JUDGE
      clock_t end = clock();
      cout<<"Executed In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
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


//Input2:
// 8 7
// 1 3
// 3 4
// 2 5
// 5 6
// 5 8
// 6 7 
// 7 8
//
//Output:
// 1: 3 
// 2: 5 
// 3: 1 4 
// 4: 3 
// 5: 2 6 8 
// 6: 5 7 
// 7: 6 8 
// 8: 5 7 
// 1