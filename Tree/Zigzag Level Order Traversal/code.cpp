// 103. Binary Tree zigzag spiral order traversal

// Problem Link:https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;

        if(root == NULL) return res;
        
        bool direction = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        
        while(!q.empty()){
            int q_size = q.size();
            vector<int> ds;
            
            while(q_size--){
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left != NULL) q.push(node->left);
                if(node-> right != NULL) q.push(node->right);
                
                ds.push_back(node->val);
            }
            if(direction == 1){
                reverse(ds.begin(), ds.end());
            }
            res.push_back(ds);
            direction = !direction;
        }
        return res;
    }
};