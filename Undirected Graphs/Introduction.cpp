#include<bits/stdc++.h>
using namespace std;

#define ll                 long long int
#define ld                 long double
#define mod                1000000007
#define inf                1e18
#define pb                 push_back
#define vi                 vector<ll>
#define vs                 vector<string>
#define pii                pair<ll,ll>
#define ump                unordered_map
#define pq_max             priority_queue<ll>
#define pq_min             priority_queue<ll,vi,greater<ll> >
#define loop(i,a,b)        for(int i=(a);i<=(b);i++)
#define looprev(i,a,b)        for(int i=(a);i>=(b);i--)
 void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
cout << *it << " = " << a << endl;
err(++it, args...);
}

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
int main(int argc, char const *argv[]) {
clock_t begin = clock();
file_i_o();

 // Write your code here....

    int v, m; cin>> v >> m;
    vector<int> adj[v+1];          // An array adj[vector<int>] containing vectors is defined

    for(int i = 1; i <= m; i++)
    {
        int x,y;
        cin >>x >>y;
        adj[x].push_back(y);
        adj[y].push_back(x);        // This line is required only for undirected graphs
    }

    for (int j = 1; j <= v; j++)
    {
        cout<<j<<": ";
        for(auto it : adj[j])
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }



    #ifndef ONLINE_JUDGE
      clock_t end = clock();
      cout<<"Executed In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}
//*****************************************************************************************************************************************************************************************
// Input:
// 7 7 
// 1 2
// 1 3
// 2 4
// 2 5
// 2 6
// 2 7
// 7 3
//
//
// Output:
// 0: 
// 1: 2 3 
// 2: 4 5 6 7 
// 3: 
// 4: 
// 5: 
// 6: 
// 7: 3 
//*****************************************************************************************************************************************************************************************
