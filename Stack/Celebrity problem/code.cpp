#include <bits/stdc++.h>
using namespace std;

#define ll long long int

void file_i_o()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int celebrity(vector<vector<int>> &M, int n){
    stack<int> st;


/*  Taking   all the elements into the stack          */    
    for(int i = 0; i<n; i++) st.push(i);

/* Running the loop until there is 1 element left into the stack */
    while(st.size() > 1) {
        int A = st.top();
        st.pop();
        int B = st.top();
        st.pop();
/* if A knows B then M[A][B] will be equlas to 1
   if B knows A then M[B][A] will be equals to 1
*/
        if(M[A][B] == 1) st.push(B);
        else if(M[B][A] == 1) st.push(A);
    }
    int C = st.top();
/*
Note: For the celebrity:
      i) All the rows will be zero('0')
      ii) All the cols will be one('1')

      Checking this condition for the potential candidate
*/    

    for(int k = 0; k < n; k++){
        if(M[C][k] == 1) return -1;
        if(k != C and M[k][C] == 0) return -1;
    }

    return C;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int n; cin>>n;
    vector<vector<int> > mat(n, vector<int> (n, 0));
    for(int i = 0; i< n; i++){
        for(int j = 0; j<n ;j++)
        cin>>mat[i][j];
    }

    for(auto it: mat){
        for(auto x: it) cout<<x<<" ";
        cout<<endl;
    }
    
    cout<<celebrity(mat, n);



#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n Executed In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}