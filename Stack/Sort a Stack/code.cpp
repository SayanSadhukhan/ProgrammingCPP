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



void sorted_insert(stack<int> &st, int x){
    if(st.empty() or st.top() < x){
        st.push(x);
        return;
    }
   
    int topEle = st.top();
    cout<<"From sorted insert  ";
cout<<"                 "<<topEle<<" "<<x<< endl;

    st.pop();
    sorted_insert(st, x);
    st.push(topEle);
}

void sortStack(stack<int> &st){
    if(st.empty()) return;

    int top = st.top();
    st.pop();
    cout << "From sortStack" << top << endl;
    sortStack(st);
    sorted_insert(st, top);
    cout << "From sortStack   end" << top << endl;
}




int main(int argc, char const *argv[]) 
{
clock_t begin = clock();
file_i_o();
// Write your code here....
    int n; cin>>n;
    stack<int> st;
    for(int i = 0; i < n; i++) {
        int temp; cin>>temp;
        st.push(temp);
    }
    sortStack(st);
cout<<"Displaying stack "<<endl;
    while(!st.empty()){
        int top = st.top();
        cout<<top<<endl;
        st.pop();
    }
//    displayStack(st);

    

#ifndef ONLINE_JUDGE 
clock_t end = clock();
cout<< "\n\n Executed In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
#endif 
    return 0;
}