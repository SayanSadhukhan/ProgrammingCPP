
/*https : // leetcode.com/problems/sliding-window-maximum/submissions/                 */
/*       SLIDING WINDOW MAXIMUM      */

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

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (!dq.empty() and (dq.front() == i - k))
            dq.pop_front();

        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) ans.push_back(nums[dq.front()]);
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    vector<int> nums;
    int n;
    cin >> n;
    int k = 3;
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        nums.push_back(v);
    }
    /* Displaying the vector*/
    for (int x : nums)
    {
        cout << x << " ";
    }
    cout << endl;

    vector<int> ans = maxSlidingWindow(nums, k);

    for (int x : ans)
        cout << x<<" ";
    cout << endl;

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n Executed In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}