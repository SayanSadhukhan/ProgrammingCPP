class Solution
{

private:
    void getLeftSmaller(vector<int> &arr, vector<int> &lse)
    {
        stack<int> st;
        for (int i = 0; i < arr.size(); i++)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            if (!st.empty())
                lse[i] = st.top() + 1;
            else
                lse[i] = 0;

            st.push(i);
        }
    }
    void getRightSmaller(vector<int> &arr, vector<int> &rse)
    {
        stack<int> st;

        for (int i = arr.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            if (!st.empty())
                rse[i] = st.top() - 1;
            else
                rse[i] = arr.size() - 1;

            st.push(i);
        }
    }
    int maxRectangleInRow(vector<int> &arr, int ind)
    {
        int n = arr.size();
        vector<int> lse(n, -1); /* For getting left smaller elememts */
        vector<int> rse(n, -1); /* For getting right smaller elements */

        int maxi = INT_MIN;

        getLeftSmaller(arr, lse);  /* Getting left smaller elememnts array for arr*/
        getRightSmaller(arr, rse); /* Getting right smaller elements array for arr */

        // cout<<ind<<endl;
        // for(int x: arr) cout<<x<<" ";
        // cout<<endl;
        // for(int i = 0; i< n; i++){
        //     cout<<lse[i] <<" ";
        // }
        // cout<<endl;
        // for(int i = 0; i< n; i++){
        //     cout<<rse[i] <<" ";
        // }
        // cout<<endl;

        /* Calculating max area rectangle for arr */
        for (int i = 0; i < n; i++)
        {
            int area = arr[i] * (rse[i] - lse[i] + 1);
            maxi = max(maxi, area);
        }
        // cout<<"finished  "<<endl;
        // cout<<maxi<<endl;
        return maxi;
    }

public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int maxi = INT_MIN;
        /* New matrix(mat) declared to store type-casted intergers */
        vector<vector<int>> mat(matrix.size(), vector<int>(matrix[0].size(), 0));

        /* Converting char elments to integers in mat*/
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                mat[i][j] = matrix[i][j] - '0'; // converting char to int
                // cout<<mat[i][j]<<" ";
            }
            // cout<<endl;
        }
        // cout<<endl;

        /* Updating every row with summation of its previous row elements */
        for (int i = 1; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j] != 0)
                    mat[i][j] += mat[i - 1][j];
                // cout<<mat[i][j]<<" ";
            }
            // cout<<endl;
        }

        for (int i = 0; i < matrix.size(); i++)
        {
            vector<int> arr(matrix[0].size(), 0);
            /* Copying each row into arr vector for getting max rectangle at each row */
            for (int a = 0; a < matrix[0].size(); a++)
            {
                arr[a] = mat[i][a];
            }
            /* Calling maxRectangleInRow function for a particular row */
            int mx = maxRectangleInRow(arr, i);
            maxi = max(maxi, mx);
        }
        //         cout<<"finished"<<endl;
        return maxi;
    }
};