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
/*      Removing smaller elements present it the stack            */
/*Because we need greater element present at left */            
            while (!st.empty() and price[st.top()] <= price[i])
            {
                st.pop();
            }

            if (!st.empty())
            {
                span[i] = i - st.top();   /*Assigning number of days interval between 
                left greater and current element
                */
            }
            else
/*  If nothing is present on stack that means there is nothing present on left which is 
greater than current element 
*/            
                span[i] = i + 1;     /*Span array maintatins 1 based indexing */

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