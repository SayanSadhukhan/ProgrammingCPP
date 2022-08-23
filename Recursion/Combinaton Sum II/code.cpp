/* Problem Link: https://leetcode.com/problems/combination-sum-ii/                                        */

class Solution
{
private:
    void find_Combinations(vector<int> candidates, int index, int &sum, int target, vector<int> &subset, vector<vector<int>> &ans)
    {
        if (target == sum)
        {
            ans.push_back(subset);
            return;
        }
        if (index == candidates.size())
            return;
        if (sum > target)
            return;

        /* Taking ith element */
        subset.push_back(candidates[index]);
        sum += candidates[index];
        find_Combinations(candidates, index + 1, sum, target, subset, ans);
        sum -= candidates[index];
        subset.pop_back();

        /* Ignoring same elements to get unique subsets */
        while (index + 1 < candidates.size() and candidates[index + 1] == candidates[index])
            index++;
        /* ignoring ith element */
        find_Combinations(candidates, index + 1, sum, target, subset, ans);
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<int> subset;
        vector<vector<int>> ans;
        int sum = 0;
        sort(candidates.begin(), candidates.end());
        find_Combinations(candidates, 0, sum, target, subset, ans);
        /*
        Debugging purpose
        Printing all the subsets inside ans variable
        for(auto it: ans){
                    for(auto x: it){
                        cout<<x;
                    }
                    cout<<endl;
                }
        */
        return ans;
    }
};