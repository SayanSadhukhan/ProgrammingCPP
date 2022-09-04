// Next Greater Element

// Problem Link: https://leetcode.com/problems/next-greater-element-i/submissions/

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> nge(nums2.size(), 0);
        vector<int> ans(nums1.size(), 0);
        stack<int> st;

        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            if (st.empty())
            {
                nge[i] = -1;
                st.push(nums2[i]);
            }
            else if (st.top() <= nums2[i])
            {
                while (!st.empty() and st.top() <= nums2[i])
                {
                    st.pop();
                }
                if (!st.empty())
                    nge[i] = st.top();
                else
                    nge[i] = -1;
                st.push(nums2[i]);
            }
            else
            {
                nge[i] = st.top();
                st.push(nums2[i]);
            }
        }

        for (int j = 0; j < nums1.size(); j++)
        {
            for (int k = 0; k < nums2.size(); k++)
            {
                if (nums1[j] == nums2[k])
                {
                    ans[j] = nge[k];
                }
            }
        }

        return ans;
    }
};