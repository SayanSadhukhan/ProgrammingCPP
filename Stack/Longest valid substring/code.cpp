/*
Problem Link: https://practice.geeksforgeeks.org/problems/valid-substring0624/1
*/

//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for c++
class Solution
{
public:
    int findMaxLen(string s)
    {
        // code here
        int len = s.length();
        stack<int> st;
        int maxi = 0;
        for (int i = 0; i < len; i++)
        {

            /* If it's a match then pop() the stack top   */
            if (s[i] == ')' and !st.empty() and s[st.top()] == '(')
            {
                st.pop();
            }

            /*Pushing everything into the stack unless it is match with the stack top*/
            else
                st.push(i);
        }

        /* Some unbalanced paranthesis still might be left in the stack

        Checking if the substring exists in between those indexes in the stack
        */
        int curr = len;
        while (!st.empty())
        {
            maxi = max(maxi, (curr - st.top() - 1));
            curr = st.top();
            st.pop();
        }
        return max(maxi, curr);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends