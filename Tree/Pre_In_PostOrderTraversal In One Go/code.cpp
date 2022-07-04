#include<bits/stdc++.h>
using namespace std;

#define  inf   1e9;


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

typedef struct node{
    int val ;
    node *left ;
    node *right ;
 
    
 }node;

node* newNode(int data){
    node * n = (node*)malloc(sizeof(node));
    n -> val = data;
    n->left = NULL;
    n->right = NULL;

    return n;
        
}

void dispPreOrder(node* root){
    if(root == NULL ) return;
    cout<<root->val<<" ";
    dispPreOrder(root->left);
    dispPreOrder(root->right);
}

void dispInOrder(node* root){
    if(root == NULL) return;

    dispInOrder(root->left);
    cout<<root->val<<" ";
    dispInOrder(root->right);
}

void dispPostOrder(node* root){
    if(root == NULL) return;

    dispPostOrder(root->left);
    dispPostOrder(root->right);
    cout<<root->val<<" ";
}

void PreInPost_OrderTraverse(node* root, vector<int> &Pre, vector<int> &In, vector<int> &Post){
    stack<pair< node* , int>> st;
    st.push({root, 1});

    while (!st.empty())
    {
        node* tmp = st.top().first;
        int num = st.top().second;
        st.pop();

        if(root == NULL) return;

        if(num == 1){
            Pre.push_back(tmp->val);
            num++;
            st.push({tmp,num});
            if(tmp->left != NULL) st.push({tmp->left, 1});
            
        }
        else if(num == 2){
            In.push_back(tmp->val);
            num++;
            st.push({tmp, num});
            if(tmp ->right != NULL) st.push({tmp->right, 1});

        }
        else if(num == 3){
            Post.push_back(tmp->val);

        }
    }
    
}

int main(int argc, char const *argv[]) {
clock_t begin = clock();
file_i_o();

 // Write your code here....
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    vector<int> pre, in, post;

    PreInPost_OrderTraverse(root, pre, in, post);

    cout<<"Pre-Order Traversal "<<endl;
    dispPreOrder(root); cout<<endl;
    for(int x: pre){
        cout<<x<<" ";
    }
    cout<<endl;

    cout<<"In-order Traversal "<<endl;
    dispInOrder(root); cout<<endl;
    for(int x: in) cout<<x<<" ";
    cout<<endl;

    cout<<"Post-order Travesal"<<endl;
    dispPostOrder(root); cout<<endl;
    for(int x: post){
        cout<<x<<" ";
    }
    cout<<endl;

    #ifndef ONLINE_JUDGE
      clock_t end = clock();
      cout<<"Executed In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}