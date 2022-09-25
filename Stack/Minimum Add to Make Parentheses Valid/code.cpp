/*
    Problem Link: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/submissions/
*/

class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (!st.empty() and s[i] == ')' and st.top() == '(')
            {
                st.pop();
            }
            else if (s[i] == '(' or s[i] == ')')
                st.push(s[i]);
        }

        return st.size();
    }
};