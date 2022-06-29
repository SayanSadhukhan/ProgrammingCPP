// Problem Link: https://leetcode.com/problems/binary-tree-postorder-traversal/

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        if(root == NULL) return ans;
        
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        
        st1.push(root);
        while(true){
            if(st1.empty()) break;
            
            TreeNode* node = st1.top();
            st1.pop();
            
            if(node->left != NULL) st1.push(node->left);
            if(node->right != NULL) st1.push(node-> right);
            st2.push(node);
        }
        
        while(!st2.empty()){
            TreeNode* tmp = st2.top();
            st2.pop();
//            cout<<tmp->val<<" ";
            ans.push_back(tmp->val);
        }
        return ans;
    }
};