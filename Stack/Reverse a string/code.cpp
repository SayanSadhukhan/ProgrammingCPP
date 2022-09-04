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

char *reversestr(char *S, int len)
{
    // code here
    stack<char> st;
    for(int j = 0; j < len; j++){
     st.push(S[j]);
    }
    int ind = 0;
    while(!st.empty()){
        S[ind] = st.top();
        st.pop();
        ind++;
    }
 
    return S;
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    int n;
    cin >> n;
    char str[50];
    for (int i = 0; i < n; i++)
        cin >> str[i];
    reversestr(str, n);

    for(int j = 0; j< n; j++){
        cout<<str[j];
    }

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n Executed In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}