/*
Problem Link: https://leetcode.com/problems/trapping-rain-water/
*/

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        stack<int> st;
        int l_max[n];
        memset(l_max, 0, n); /* Setting every element of the array to zero( 0 )*/
        int r_max[n];
        memset(r_max, 0, n);
        int water_acquired[n];
        int maxi = INT_MIN;

        /* Preparing the l_max array i.e. the left max array
        It will give maximum elevation in the left for every element in the array
        */
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() and height[st.top()] <= height[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                l_max[i] = 0;
            }
            else
            {
                if (height[st.top()] > maxi)
                {
                    maxi = height[st.top()];
                    l_max[i] = maxi;
                }
                else
                    l_max[i] = maxi;
            }
            st.push(i);
        }
        /*  clearing the stack        */
        while (!st.empty())
            st.pop();
        maxi = INT_MIN;
        /* Preparing the r_max array i.e. the right max array
        It will give maximum elevation in the right for every element
        */
        for (int j = n - 1; j >= 0; j--)
        {
            while (!st.empty() && height[st.top()] <= height[j])
            {
                st.pop();
            }

            if (!st.empty())
            {
                if (height[st.top()] > maxi)
                {
                    maxi = height[st.top()];
                    r_max[j] = maxi;
                }
                else
                {
                    r_max[j] = maxi;
                }
            }
            else
            {
                r_max[j] = 0;
            }

            st.push(j);
        }
        /*    Calculating water acquired by each and every element          */
        for (int k = 0; k < n; k++)
        {
            int water = 0;
            if (min(l_max[k], r_max[k]) - height[k] > 0)
            {
                water_acquired[k] = min(l_max[k], r_max[k]) - height[k];
            }
            else
                water_acquired[k] = 0;
        }
        /*  Getting total summation of water */

        int water_sum = 0;
        for (int x : water_acquired)
            water_sum += x;

        return water_sum;
    }
};