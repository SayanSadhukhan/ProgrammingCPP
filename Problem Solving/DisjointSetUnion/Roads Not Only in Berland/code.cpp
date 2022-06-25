// Problem Link: https://codeforces.com/problemset/problem/25/D


#include <bits/stdc++.h>
using namespace std;

#define ll long long int


class DSU
{
    private:
    vector<int> size, parent;

    public:
    DSU(int n){
        for(int i = 0; i <= n; i++){
            parent.push_back(i);
            size.push_back(1);
        }
    }

    int findPar(int node){
        if(parent[node] == node) return node;
        return parent[node] = findPar(parent[node]);
    }

    void unionDSU(int a, int b){
        int pa = findPar(a);
        int pb = findPar(b);

        if(pa == pb) return;

        if(size[pa] > size[pb]){
            parent[pb] = pa;
            size[pa] += size[pb];
        }
        else if(size[pa] < size[pb] ){
            parent[pa] = pb;
            size[pb] += size[pa];
        }
        else{
            parent[pb] = pa;
            size[pa] += size[pb];
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


int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int n; 
    cin>>n;
    vector<pair<int, int>> extraRoads;
    DSU d(n+1);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin>>a>>b;
        if(d.findPar(a) == d.findPar(b))
            extraRoads.push_back({a, b});
        else{
            d.unionDSU(a, b);
        }

    }

    if(extraRoads.size() == 0) {
        cout<<0<<endl;
        return 0;
        }

    set<int> st;
    for(int i = 1; i <= n; i++){
        st.insert(d.findPar(i));
    }

    int x = st.size();
    cout<<x-1<<endl;

    vector<int> vec(st.begin(), st.end());

    int j = 0; 
    for(int i = 1; i<= x - 1; i++){
        cout<<extraRoads[j].first<<" "<<extraRoads[j].second
        <<" "<<vec[i]<<" "<<vec[i-1];
        j++;
    }


    

    #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n Executed In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}