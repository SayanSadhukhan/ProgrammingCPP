class Solution
{
private:
    vector<string> ans;
    int getMinRemoval(string &s)
    {
        stack<char> st;
        for (char c : s)
        {
            if (c == '(')
                st.push(c);
            else if (c == ')')
            {
                if (!st.empty() and st.top() == '(')
                    st.pop();
                else
                    st.push(c);
            }
        }
        return st.size();
    }

    void allPossibleValidParantheses(string str, int minRemoval, unordered_map<string, int> &mp)
    {
        if (mp[str] != 0)
            return;
        else
            mp[str]++;
        if (minRemoval < 0)
            return;
        if (minRemoval == 0)
        {
            if (getMinRemoval(str) == 0)
            {
                ans.push_back(str);
            }
            return;
        }

        for (int i = 0; i < str.length(); i++)
        {
            string left = str.substr(0, i);
            string right = str.substr(i + 1);
            allPossibleValidParantheses(left + right, minRemoval - 1, mp);
        }
        return;
    }

public:
    vector<string> removeInvalidParentheses(string s)
    {
        unordered_map<string, int> mp;
        int mR = getMinRemoval(s);
        // vector<string> ans;
        allPossibleValidParantheses(s, mR, mp);

        // for(auto it = st.begin(); it!=st.end(); it++) ans.push_back(*it);
        return ans;
    }
};