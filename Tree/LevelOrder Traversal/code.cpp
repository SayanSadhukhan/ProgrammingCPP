//Problem Link: https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL ) return ans;
        queue<TreeNode* > q;
        q.push(root);
        
        while(!q.empty()){
            int q_size = q.size();
            vector<int> tmp;
            for(int i =0; i < q_size; i++){ 
                TreeNode* node = q.front();
                q.pop();
                tmp.push_back(node->val);
                if(node->left != NULL ) q.push(node->left);
                if(node -> right != NULL) q.push(node->right);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};