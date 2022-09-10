#include<bits/stdc++.h>
using namespace std;

#define ll                long long int


void file_i_o()
{
ios_base::sync_with_stdio(0); 
cin.tie(0); 
cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
#endif
}


/* Evaluate the expression presented in postfix     */
int evaluatePostfix(string S)
{
    // Your code here
    stack<int> st;

    for (int i = 0; i < S.length(); i++)
    {
        int temp = 0;

        if (S[i] == '*')
        {
            int A = st.top();
            st.pop();
            int B = st.top();
            st.pop();

            st.push(B * A);
        }
        else if (S[i] == '/')
        {
            int A = st.top();
            st.pop();
            int B = st.top();
            st.pop();

            st.push(B / A);
        }
        else if (S[i] == '+')
        {
            int A = st.top();
            st.pop();
            int B = st.top();
            st.pop();

            st.push(A + B);
        }
        else if (S[i] == '-')
        {
            int A = st.top();
            st.pop();
            int B = st.top();
            st.pop();

            st.push(B - A);
        }
        else
        {
            temp = S[i] - '0';
            st.push(temp);
        }
    }
    //        cout<<st.top();
    if (st.size() != 1)
        return -1;

    return st.top();
}

int main(int argc, char const *argv[]) 
{
clock_t begin = clock();
file_i_o();
// Write your code here....
    char a = '9';
    int b = 5;
    int a1 = a - '0';
    int a2 = a - 48;
    int a3 = atoi(&a);
    cout<<a1*b<<" "<<a1+b<<endl;
    cout<<a2*b<<" "<<a2+b<<endl;
    cout<<a3*b<<" "<<a3+b<<endl;

    string S = "231*+9-";

    cout<<evaluatePostfix(S);


#ifndef ONLINE_JUDGE 
clock_t end = clock();
cout<< "\n\n Executed In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
#endif 
    return 0;
}