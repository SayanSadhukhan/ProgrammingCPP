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


/*                                            Generating all subsets possible                                          */
void generateans(vector<int> arr, int ind, vector<int> &Sub_st, vector<vector<int>> &ans)
{
    if (ind == arr.size())
    {
        ans.push_back(Sub_st);
        return;
    }
/*Calling recursion  excluding an element */
    generateans(arr, ind+1, Sub_st, ans);
/*Calling recursion  including an element into the subset */
    Sub_st.push_back(arr[ind]);
    generateans(arr, ind+1, Sub_st, ans);
    Sub_st.pop_back();                            /* Backtracking: removing the element that was included to return it to 
 its previous state while returning from bottom */
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int n;
    cin >> n;
    vector<int> arr, Sub_st;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        arr.push_back(ele);
    }
// Display the input array
    // for (auto x : arr)
    // {
    //     cout<<x<<" ";
    // }
    vector<vector<int>> ans;
    generateans(arr, 0, Sub_st, ans);

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n Executed In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}