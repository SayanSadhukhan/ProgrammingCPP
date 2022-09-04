/*  LARGEST RECTANGLE IN THE HISTOGRAM
    Problem Link: https://takeuforward.org/data-structure/area-of-largest-rectangle-in-histogram/

*/

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        int left_smaller_b[n];
        memset(left_smaller_b, 0, n);
        int right_smaller_b[n];
        memset(right_smaller_b, 0, n);

        stack<int> st;

        /*       Constructing left_smaller_b[] array        */
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() and heights[st.top()] >= heights[i])
                st.pop();

            if (st.empty())
            {
                left_smaller_b[i] = 0;
            }
            else
            {
                left_smaller_b[i] = st.top() + 1;
            }
            st.push(i);
        }

        /*       Clearing the stack   */
        while (!st.empty())
            st.pop();

        /*     Constructing left_smaller_b[] array        */
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() and heights[st.top()] >= heights[i])
                st.pop();

            if (st.empty())
            {
                right_smaller_b[i] = n - 1;
            }
            else
            {
                right_smaller_b[i] = st.top() - 1;
            }
            st.push(i);
        }

        // for(auto it: left_smaller_b) cout<<it<<" ";
        // cout<<endl;
        // for(auto it: right_smaller_b) cout<<it<<" ";
        // cout<<endl;

        int rect_arr[n];
        int maxi = INT_MIN;
        /*     Calculating rectangular area for each and every element    */
        for (int j = 0; j < n; j++)
        {
            rect_arr[j] = (right_smaller_b[j] - left_smaller_b[j] + 1) * heights[j];
            maxi = max(maxi, rect_arr[j]);
            //            cout<<rect_arr[j]<<" ";
        }

        return maxi;
    }
};