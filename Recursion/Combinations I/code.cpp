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
// Combinaton Sum I
void find_CombinationSum(int i, int target, vector<int> arr,int &sum, vector<int> &subset, vector<vector<int>> &ans){
    if(sum == target ) {
        ans.push_back(subset);
        return;
    }
    if(i == arr.size()) return;
    if(sum > target) return;

// Taking ith element
    subset.push_back(arr[i]);
    sum += arr[i];
    find_CombinationSum(i, target, arr, sum,subset, ans );
    subset.pop_back();             // Backtraking: Undo the changes
    sum -= arr[i];

// Skiping ith element
    find_CombinationSum(i + 1, target, arr, sum, subset, ans);
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int n, target; cin>>n>>target;
    vector<int> arr(n, 0);
    for(int i = 0;i < n; i++){
        cin>>arr[i];
    }
    vector<int> subset;
    vector<vector<int>> ans;
    int sum = 0;
    find_CombinationSum(0, target, arr, sum, subset, ans);

// Displaying the ans
    for(auto it: ans){
        for(auto x: it){
            cout<<x;
        }
        cout<<endl;
    }    

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n Executed In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}