/*                                             Print all permuations                                   */

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

vector<vector<int>> getAll_Permutation(vector<int> arr, vector<bool> &mp, vector<int> &ds, vector<vector<int>> &ans)
{
    if(ds.size() == arr.size()){
        ans.push_back(ds);
        return ans;
    }

    for(int i = 0; i < arr.size(); i++){
        if(mp[i] == false){
            ds.push_back(arr[i]);
            mp[i] = true;
        
            ans = getAll_Permutation(arr, mp, ds, ans);
            mp[i] = false;
            ds.pop_back();
        }
    }
    
    return ans;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int n; cin>>n;
    vector<int> arr;
    for(int i = 0; i< n; i++){
        int temp; cin>>temp;
        arr.push_back(temp);
    }

    vector<int> ds;
    vector<bool> mp(n, 0);
    vector<vector<int>> ans;

    ans = getAll_Permutation(arr, mp, ds, ans); 

    for(auto it: ans){
        for(int i = 0; i < it.size(); i++){
            cout<<it[i];
        }
        cout<<endl;
    }



#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n Executed In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}

/*========================================================================================================================================*/
/******************                       Another approach                        *****************/

// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long int

// void file_i_o()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
// }

// void find_Permutations(vector<int> &arr, int ind, vector<vector<int>> &ans){
//     if(ind == arr.size()){
//         ans.push_back(arr);
//         return;
//     }

//     for(int i = ind; i < arr.size(); i++){
//         swap(arr[i], arr[ind]);
//         find_Permutations(arr, ind+1, ans);
//         swap(arr[i], arr[ind]);
//     }
// }

// int main(int argc, char const *argv[])
// {
//     clock_t begin = clock();
//     file_i_o();
//     // Write your code here....
//     int n; cin>>n;
//     vector<int> arr;
//     for(int i = 0; i< n; i++){
//         int temp; cin>>temp;
//         arr.push_back(temp);
//     }

//     vector<vector<int>> ans;
//     find_Permutations(arr, 0, ans);

//     for(auto it: ans){
//         for(int i = 0; i< it.size(); i++){
//             cout<<it[i];
//         }
//         cout<<endl;
//     }

// #ifndef ONLINE_JUDGE
//     clock_t end = clock();
//     cout << "\n\n Executed In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
// #endif
//     return 0;
// }


