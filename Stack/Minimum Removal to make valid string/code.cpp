/*
Problem Link: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
*/

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

string MinRemoveToMakeValidParantheses(string str){
    stack<pair<char, int>> st;

/*  After this operation the paratheses responsible for the string to be 
    invalid will remain in the stack.
*/    
    for (int i = 0; i < str.length(); i++)
    {
        if (!st.empty() and str[i] == ')' and st.top().first == '(')
        {
            st.pop();
        }
        else if (str[i] == '(' || str[i] == ')')
            st.push({str[i], i});
    }

/* Erasing the invalid parantheses remaining in the stack */
    while (!st.empty())
    {
        int index = st.top().second;
/*  Debugging purpose */        
        cout << index << "-->" << str[index] << endl;
        st.pop();
        str.erase(index, 1);
    }

    return str;
}


int main(int argc, char const *argv[]) 
{
clock_t begin = clock();
file_i_o();
// Write your code here....
    string str;
    cin>>str;

    string s = MinRemoveToMakeValidParantheses(str);

 //   cout<<str<<endl;
 //   str.erase(12,1);
    cout<<"Print string: "<<s;

#ifndef ONLINE_JUDGE 
clock_t end = clock();
cout<< "\n\n Executed In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
#endif 
    return 0;
}

/*

    TEST CASES

Example 1:

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.

Example 2:

Input: s = "a)b(c)d"
Output: "ab(c)d"

Example 3:

Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.





*/