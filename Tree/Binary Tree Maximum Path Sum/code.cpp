// 124. Binary Tree Maximum Path Sum
// Problem Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    
private:
    int pathSum(TreeNode* node, int &path){
        if(node == NULL) return 0;
        
        int lh = max(0,pathSum(node->left, path));
        int rh = max(0,pathSum(node-> right, path));
        
        path = max(path, lh+rh + node->val);
 //       cout<<path<<endl;
        
        return node->val + max(lh, rh);
    }
    
public:
    int maxPathSum(TreeNode* root) {
        int path = INT_MIN;
        pathSum(root, path);
        return path;
    }
};