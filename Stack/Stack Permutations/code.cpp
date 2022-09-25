/*
Problem Link: https://practice.geeksforgeeks.org/problems/stack-permutations/1
*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int isStackPermutation(int N, vector<int> &A, vector<int> &B)
    {
        stack<int> st;
        int k = 0, cnt = 0;
        for (int i = 0; i < N; i++)
        {
            if (k > N - 1)
                break;
            /*  If the ith element in A is same as kth element in B then increase count and k*/
            if (A[i] == B[k])
            {
                cnt++;
                k++;
                /*  Check if stack top element is same as Kth element in B then increase cnt and k and pop() from stack    */
                while (!st.empty() and st.top() == B[k])
                {
                    cnt++;
                    k++;
                    st.pop();
                }
            }
            /*  Otherwise push ith element from A to the stack           */
            else
                st.push(A[i]);
        }
        // cout<<cnt<<endl;
        if (cnt == N)
            return 1;
        return 0;
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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        Solution ob;
        cout << ob.isStackPermutation(n, a, b) << endl;
    }

    return 0;
}
// } Driver Code Ends