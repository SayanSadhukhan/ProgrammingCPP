/* Stock span problem :
Problem Link: https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1
*/
//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to calculate the span of stockâ€™s price for all n days.
    vector<int> calculateSpan(int price[], int n)
    {
        // Your code here
        stack<int> st;
        vector<int> span(n, 0);

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() and price[st.top()] <= price[i])
            {
                st.pop();
            }

            if (!st.empty())
            {
                span[i] = i - st.top();
            }
            else
                span[i] = i + 1;

            st.push(i);
        }
        //   for(int x: span) cout<<x<<" ";
        //   cout<<endl;
        return span;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int i, a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        vector<int> s = obj.calculateSpan(a, n);

        for (i = 0; i < n; i++)
        {
            cout << s[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends