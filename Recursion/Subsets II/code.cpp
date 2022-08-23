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

/*                                              Generating unique subsets                                   */
/*                                         Without including additional map                              */
void genUniqSubsets(vector<int> arr, int index, vector<int> &sub_st, vector<vector<int>> &ans)
{
    if (index == arr.size())
    {
        ans.push_back(sub_st);
        return;
    }


// Including an element if it occurs once in the array
    if(index == 0 or (index > 0 and arr[index - 1] != arr[index])){
        sub_st.push_back(arr[index]);
        genUniqSubsets(arr, index + 1, sub_st, ans);
        sub_st.pop_back();
    }

// Generating subsets excluding the element    
    genUniqSubsets(arr, index + 1, sub_st, ans);
}


/*                                        Generating unique subsets                                            */
/*                                            Including additional map          */


// void genUniqSubsets(vector<int> arr, int index, vector<int> &sub_st, unordered_map<int, int> mp, vector<vector<int>> &ans)
// {
//     if (index == arr.size())
//     {
//         ans.push_back(sub_st);
//         return;
//     }
//     if(mp[arr[index]] == 1) return;
//     mp[arr[index] ] = 1;

//     sub_st.push_back(arr[index]);
//     genUniqSubsets(arr, index + 1, sub_st, mp, ans);
//     sub_st.pop_back();
//     mp.erase(arr[index]);
//     genUniqSubsets(arr, index + 1, sub_st, mp, ans);
// }








int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    unordered_map<int, int> mp;

    vector<int> subset;
    vector<vector<int>> ans;
    genUniqSubsets(arr, 0, subset, ans);

    for (auto vec : ans)
    {
        cout << "[";
        for (auto i : vec)
        {
            cout << i << " ";
        }
        cout << "]" << endl;
    }

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n Executed In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}