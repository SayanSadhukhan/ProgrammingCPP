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

void disp(int v, vector<int> adj[]){
    for(int i = 0; i < v; i++){
        cout<<i<<": ";
        for(auto it: adj[i]) cout<<it<<" ";
        cout<<endl;
    }
}

void topoDFS(int n, vector<int> adj[], vector<bool> &visited, stack<int> &st ){
    // for(auto it: adj[n]){
    //     if(!visited[it]){
    //         visited[it] = 1;
    //         topoDFS(it, adj, visited, st);
    //     }
    // }
    // st.push(n);

    visited[n] = 1;
    for(auto it: adj[n]){
        if(!visited[it]){
            topoDFS(it, adj, visited, st);
        }
    }
    st.push(n);
}

void topoHelper(int v, vector<int> adj[]){
    vector<bool> visited(v+1, 0);
    stack<int> st;
    for(int i = 0; i<v; i++){
        if(!visited[i]){
            topoDFS(i, adj, visited, st);
        }
    }

    while(!st.empty()){
        int temp = st.top();
        st.pop();
        cout<<temp<<" ";
    }
    
    // vector<bool> visited(v+1, 0);
    // stack<int> st;
    // for(int i = 0; i<v; i++){
    //     if(!visited[i]){
    //         visited[i] = 1;
    //         topoDFS(i, adj, visited, st);
    //     }
    // }
    // cout<<"Toposort for the graph is given below: "<<endl;
    // while(!st.empty()){
    //     int temp = st.top();
    //     st.pop();
    //     cout<<temp<<" ";
    // }
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int v,e; cin>>v>>e;
    vector<int> arr[v+10];
    for(int i=0; i < e; i++){
        int x,y; cin>>x>>y;
        arr[x].push_back(y);
    }

    disp(v,arr);
    topoHelper(v, arr);
    #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n Executed In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}



// Test Cases
// Input:
// 6 6
// 3 1
// 2 3
// 5 0
// 5 3
// 4 0
// 4 1

// Output:
// 0: 
// 1: 
// 2: 3 
// 3: 1 
// 4: 0 1 
// 5: 0 3 
// Toposort for the graph is given below: 
// 5 4 2 3 1 0