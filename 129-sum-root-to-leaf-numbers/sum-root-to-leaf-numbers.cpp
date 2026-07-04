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
    int sumNumbers(TreeNode* root) {
        int count = 0;
        return helper(root,count);
    }
private: 

    int helper(TreeNode* root , int c){
        if(!root) return 0;
        c = c*10 + root->val;
        if(!root->left && !root->right) return c;
        
        return helper(root->left,c) + helper(root->right,c);
    }

};