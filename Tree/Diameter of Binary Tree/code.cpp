//543. Diameter of Binary Tree
// Problem Link:https: //leetcode.com/problems/diameter-of-binary-tree/

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
    int maxWidth(TreeNode* node, int &diameter){
        if(node == NULL) return 0;
        
        int lh = maxWidth(node->left, diameter);
        int rh = maxWidth(node->right, diameter);
        
        diameter = max(lh + rh, diameter);
        
        return 1 + max(lh, rh);
        
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        maxWidth(root, diameter);
        return diameter;
    }
};