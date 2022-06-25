#include <bits/stdc++.h>
using namespace std;

#define ll long long int

class DSU
{
    private: 
    vector<int> parent, size;
    public:
    DSU(int n){
        for(int i = 0; i <= n; i++){
            parent.push_back(i);
            size.push_back(1);
        }
    }

    int findPar(int node){
        if(parent[node] == node) return node;
        parent[node] = findPar(parent[node]);

        return parent[node];
    }

    void union_DSU(int m, int n){
        int pm = findPar(m);
        int pn = findPar(n);

        if(pm == pn){
            return;
        }

        if(size[pm] > size[pn]){
            parent[pn] = pm;
            size[pm] += size[pn];
        }
        else if(size[pm] < size[pn]){
            parent[pm] = pn;
            size[pn] += size[pm];
        }
        else{
            parent[pn] = pm;
            size[pm] += size[pn];
        }
    }
};


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




bool cycleDSU(int v, vector<pair<int,int>> edges){
    DSU d(v);
    
    for(auto it: edges){
        int pa = d.findPar(it.first);
        int pb = d.findPar(it.second);
        if(pa == pb){
            return true;
        }
        else {
            d.union_DSU(it.first, it.second);
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
    int v,e;
    cin>>v>>e;
    


    vector<pair<int, int>> edges;
    for(int i = 0; i < e; i++){
        int x,y;
        cin>>x>>y;
        edges.push_back({x,y});
    
    }

    cout<<cycleDSU(v, edges);


#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n Executed In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}


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
