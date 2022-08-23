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

void find_Combinations(int i, int n, int k, vector<int> &subset, vector<vector<int>> &ans){
    if(k == 0) {
        ans.push_back(subset);
        return;
    }
    if (i > n ) return;
    if( k > (n - i + 1)) return;

    subset.push_back(i);
    find_Combinations(i + 1, n, k - 1, subset, ans);

    subset.pop_back();
    find_Combinations(i + 1, n, k, subset, ans);

}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int n, k;
    cin>>n>>k;
    int i = 1;
    vector<vector<int>> ans;
    vector<int> subset;

    find_Combinations(1, n, k, subset, ans);
    for(auto it: ans){
        for(auto j: it){
            cout<<j;
        }
        cout<<endl;
    }


#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n Executed In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}