/*
Letter Combinations of a phone number
Problem Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
*/

class Solution
{
private:
    void find_AllLetterCombinations(string &s, int ind, unordered_map<char, string> &mp, string &temp, vector<string> &ans)
    {
        if (ind == s.length())
        {
            ans.push_back(temp);
        }

        string str = mp[s[ind]];
        for (int i = 0; i < str.length(); i++)
        {
            temp.push_back(str[i]);
            find_AllLetterCombinations(s, ind + 1, mp, temp, ans);
            temp.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        string temp = "";
        vector<string> ans;
        if (digits == "")
            return ans;

        find_AllLetterCombinations(digits, 0, mp, temp, ans);
        /*
                for(auto it: ans){
                    for(auto st: it) cout<<st;
                    cout<<endl;
                }
        */
        return ans;
    }
};