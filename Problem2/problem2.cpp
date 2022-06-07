// Find minimum number moves to reach the end
// start = 2 end = 40
// arr[] = {2, 5, 10}
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
int findMinimumSteps(int arr[], int n, int start, int en)
{
    vector<bool> v(en + 1, 0);
    v[start] = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(start, 0));
    while (!q.empty())
    {
        int node = q.front().first;
        int steps = q.front().second;
        q.pop();
        if (node == en)
            return steps;
        for (int i = 0; i < n; i++)
        {
            int dest = node * arr[i];
            if (!v[dest] and dest <= en)
            {
                v[dest] = 1;
                q.push({dest, steps +1});
            }
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int start, en, n;
    cin >> start >> en;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << findMinimumSteps(arr, n, start, en);

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n Executed In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}