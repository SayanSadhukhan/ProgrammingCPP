// LintCode Medium
// Problem Link: https://www.lintcode.com/problem/878/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {

private:
    bool isLeaf(TreeNode* node){
        return (node-> left == NULL)&&(node-> right == NULL);
    }
    void addLeftEdges(TreeNode* node, vector<int> &ans){
        TreeNode* curr = node -> left;
  //      cout<<"addLeftEdges"<<endl;
        while(curr!= NULL){
    //        cout<<"Adding left edges"<<endl;
            if(!isLeaf(curr)) ans.push_back(curr-> val);
            if(curr->left != NULL) curr = curr->left;
            else curr = curr -> right;
        }
    }  

    void addLeaves(TreeNode* node, vector<int> &ans){
       // cout<<"addLeaves"<<endl;
        
        if(isLeaf(node)) ans.push_back(node->val);

        if(node->left) addLeaves(node->left, ans);
        if(node->right) addLeaves(node->right,ans);
    }  

    void addRightEdges(TreeNode *node, vector<int> &ans){
      //  cout<<"Add right edges"<<endl;
        TreeNode* tmp = node->right;
        vector<int> edges;
        
        while(tmp){
            if(!isLeaf(tmp)) edges.push_back(tmp->val);
            if(tmp->right != NULL) tmp = tmp -> right;
            else tmp = tmp->left;
        }
        reverse(edges.begin(), edges.end());
        for(int x: edges){
            ans.push_back(x);
        }
    }
public:
    /**
     * @param root: a TreeNode
     * @return: a list of integer
     */
    vector<int> boundaryOfBinaryTree(TreeNode *root) {
        // write your code here
        vector<int> ans;
        if(root == NULL) return ans;
        if(!isLeaf(root)) ans.push_back(root->val);
        addLeftEdges(root, ans);
        addLeaves(root, ans);
        addRightEdges(root, ans);
    }
};