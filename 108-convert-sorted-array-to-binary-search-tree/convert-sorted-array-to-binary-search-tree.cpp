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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums,0,nums.size() - 1);
    }

private:

    TreeNode* helper(vector<int>& nums , int st , int ed){
        if(st>ed) return nullptr;
        int m = st + (ed - st) /2 ;
        TreeNode* curr = new TreeNode(nums[m]);

        curr->left = helper(nums,st,m-1);
        curr->right = helper(nums,m+1,ed);

        return curr;
    }

};