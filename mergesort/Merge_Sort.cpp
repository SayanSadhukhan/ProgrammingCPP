// Write Merge-sort algorithm



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
// Display
void disp(vector<int> v)
{
    for (int x: v )
    {
        cout << x << " ";
    }
    cout << endl;
}

// Merge
void merge(vector<int> &arr, int l, int mid, int r)
{

    int left = l;
    int right = mid;

    vector<int> tp;
    while (left <= mid - 1 and right <= r)
    {

        if (arr[left] <= arr[right])
        {
            tp.push_back(arr[left++]);
        }
        else
        {
            tp.push_back(arr[right++]);
        }
    }
    while (left <= mid - 1)
    {
        tp.push_back(arr[left++]);
    }

    while (right <= r)
    {
        tp.push_back(arr[right++]);
    }

    // Copying tp to main arr
    for (int j = l; j <= r; j++)
    {
        arr[j] = tp[j - l];
    }
    
}

// Merge sort
void merge_sort(vector<int> &arr, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int mid = (l + r) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);
    merge(arr, l, mid + 1, r);

    return;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int n;
    cin >> n;
    vector<int> arr(n,0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    disp(arr);

    merge_sort(arr, 0, n - 1);
    cout << "Inside main: " << endl;
    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << endl;

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n Executed In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}
