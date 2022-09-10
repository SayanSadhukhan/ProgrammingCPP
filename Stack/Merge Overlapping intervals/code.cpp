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

void mergeOverlappingIntervals(vector<vector<int>> &vec){
    stack<int> st;
    vector<vector<int>> ans;
    sort(vec.begin(), vec.end());
    st.push(vec[0][0]);
    st.push(vec[0][1]);
    for(int i = 1; i< vec.size(); i++){
        int top = st.top();
        st.pop();
        if(top >= vec[i][0]){
           int maxi = max(top, vec[i][1]);
           st.push(maxi);
        }
        else if(st.size() == 2){
            vector<int> temp(2,0);
            int x = st.top(); st.pop();
            temp[1] = x;
            x =st.top(); st.pop();
            temp[0] = x;
            cout<<temp[0]<<" "<<temp[1];
            cout<<endl;
            ans.push_back(temp);

            st.push(vec[i][0]);
            st.push(vec[i][1]);
        }

    }
    cout<<endl<<"ans "<<endl;
    for (auto v : ans)
    {
        for (auto i : v)
            cout << i << " ";
        cout << endl;
    }
    return ;
}

int main(int argc, char const *argv[]) 
{
clock_t begin = clock();
file_i_o();
// Write your code here....
    vector<vector<int>> vec; 
    int n; cin>>n;
    for(int i = 0; i<n; i++) {
        vector<int> temp;
        int a; cin>>a; temp.push_back(a);
        int b; cin>>b; temp.push_back(b);
        vec.push_back(temp);
    }

        
    mergeOverlappingIntervals(vec);
    for(auto v: vec){
        for(auto i: v) cout<<i<<" ";
        cout<<endl;
    }
                    
#ifndef ONLINE_JUDGE 
clock_t end = clock();
cout<< "\n\n Executed In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
#endif 
    return 0;
}