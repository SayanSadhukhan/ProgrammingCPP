#include<bits/stdc++.h>
using namespace std;

#define inf                1e18



class node
{
    public:
    int u, v, wt;
    node(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
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
// define functions...


bool comp(node a, node b)
{
   return a.wt < b.wt;
}






int main(int argc, char const *argv[]) {
clock_t begin = clock();
file_i_o();

 // Write your code here....
    int v, e; cin>>v>>e;
    vector<node> container;

    for (int i = 1; i <= e; i++)
    {
        int u,v,wt; cin>>u>>v>>wt;
        container.push_back(node(u, v, wt));
    }
    
    vector <int> rank(v+1, 0);
    int parent[v+1];
    for (int j = 1; j <= v; j++)
    {
        parent[j] = j;
    }
    




    #ifndef ONLINE_JUDGE
      clock_t end = clock();
      cout<<"Executed In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}
