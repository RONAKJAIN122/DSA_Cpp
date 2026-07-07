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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        bool ans = true;
        helper(root, ans);
        return ans;
    }
private:

    int helper(TreeNode* root , bool &b){
        if(!root) return 0;
        int lh = helper(root->left,b);
        int rh = helper(root->right,b);
        int d = lh-rh;
        if(d != -1 && d != 0 && d != 1){
            b = false;
        }
        return max(lh , rh) + 1;
    }
};