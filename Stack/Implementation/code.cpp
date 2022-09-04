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

class STACK
{

   int top;
   int *arr;
   int size;
   public:
   STACK(){
     top = -1;
     size = 1000;
     arr = new int[size];
   }

/*  Declaring functions */
    void push(int ele);
    int pop();
    int Size();
   

};


/*  Defining functions  */
    void STACK :: push(int ele){
        top++;
        arr[top] = ele;
    }

    int STACK ::  Size()
    {
        return top + 1;
    }

    int STACK :: pop()
    {
        top--;
        return arr[top + 1];
    }

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    STACK st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    cout<<st.Size()<<endl;
    cout<<"Popped "<<st.pop()<<endl;
    cout<<st.Size()<<endl;

    while(st.Size()){
        cout<<st.pop()<<endl;
    }

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n Executed In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}