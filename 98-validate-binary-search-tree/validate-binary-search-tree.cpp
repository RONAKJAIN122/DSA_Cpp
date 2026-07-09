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
    bool isValidBST(TreeNode* root) {
        return helper(root,LLONG_MIN,LLONG_MAX);
    }
private:

    bool helper(TreeNode *root , long long min , long long max){
        if(!root) return 1;

        if(!(min < root->val && root->val < max)) return 0;
        
        return helper(root->left,min,root->val) && helper(root->right,root->val,max);

    }

};