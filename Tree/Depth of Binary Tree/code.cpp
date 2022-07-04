// 104. Maximum Depth of Binary Tree
// Problem Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/

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
    int height(TreeNode* node){
        if(node == NULL) return 0;
        
        int l = height(node->left);
        int r = height(node-> right);
        
        return 1 + max(l,r);
    }
public:
    int maxDepth(TreeNode* root) {
        return height(root);
    }
};