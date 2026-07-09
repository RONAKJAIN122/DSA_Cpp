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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nums;    
        inorder(root,nums);
        return helper(nums,0,nums.size() - 1);
    }
private:

    void inorder(TreeNode* root, vector<int> &n){
        if(!root) return;
        inorder(root->left,n);
        n.push_back(root->val);
        inorder(root->right,n);
    }

    TreeNode* helper(vector<int>& nums , int st , int ed){
        if(st>ed) return nullptr;
        int m = st + (ed - st) /2 ;
        TreeNode* curr = new TreeNode(nums[m]);

        curr->left = helper(nums,st,m-1);
        curr->right = helper(nums,m+1,ed);

        return curr;
    }
};