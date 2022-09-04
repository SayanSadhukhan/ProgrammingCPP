class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        vector<int> nge(nums.size(), -1);
        stack<int> st;
        int n = nums.size();

        for (int i = 2 * n - 1; i >= 0; i--)
        {
            /*     Remove all the smaller elements      */
            while (!st.empty() && st.top() <= nums[i % n])
            {
                st.pop();
            }
            /*     Assigning the next greater element after removing the smaller elements     */
            if (!st.empty() and i < n)
                nge[i] = st.top();

            st.push(nums[i % n]);
        }
        return nge;
    }
};