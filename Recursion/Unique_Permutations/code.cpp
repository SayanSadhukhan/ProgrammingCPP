/*                                         Print all unique permutations                                  */

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

void genUniqPermut(vector<int> &arr, int index, vector<vector<int>> &ans)
{
    if (index == arr.size())
    {
        ans.push_back(arr);
        return;
    }

    for (int i = index; i < arr.size(); i++)
    {
/* Debugging purpose */
        // cout<<"\n"<<i<<endl;
        if(i > index and arr[i] == arr[i - 1]) continue;             // Cancelling duplicate calls
        swap(arr[i], arr[index]);
/* Debugging purpose */        
        // cout<<"Permutation called for index: "<<index<<" and i = " <<i<<endl;
        genUniqPermut(arr, index + 1, ans);
/* Debugging purpose */
        // cout<<index<<" "<<i<<endl;
        swap(arr[i], arr[index]);
    }
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        cin >> temp;
        arr.push_back(temp);
    }

    vector<vector<int>> ans;
    genUniqPermut(arr, 0, ans);
/*Display the recieved output                          */
    for (int j = 0; j < ans.size(); j++)
    {
        for (int k = 0; k < ans[j].size(); k++)
        {
            cout << ans[j][k];
        }
        cout << endl;
    }

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n Executed In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}