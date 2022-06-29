// Problem Link: https://leetcode.com/problems/binary-tree-inorder-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack< TreeNode*> st;
        
        if(root == NULL) return ans;
        st.push(root);
        
        TreeNode* node = root->left;
        while(1){
            
            if(node != NULL){
                st.push(node);
                node = node -> left;
            } 
            else{
                if(st.empty() ) return ans; 
                TreeNode* temp = st.top();
                st.pop();
                ans.push_back(temp-> val);
//                cout<<temp->val<<" ";
                node = temp -> right;
            }
        }
        return ans;
    }
};