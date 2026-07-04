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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        int l = height(root);
        if(l<k) return -1;
        vector<long long> a (l+1,0);
        
        helper(root,a,1);
        
        sort(a.begin() , a.end());
        return a[l-k+1];
    }
private:

    int height(TreeNode *root){
        if(!root) return 0;
        int l = height(root->left);
        int r = height(root->right);
        return max(l,r) + 1;
    }


    void helper(TreeNode *r , vector<long long> &a , int l){
        if(!r) return;

        a[l] += r->val;

        helper(r->left,a,l+1);
        helper(r->right,a,l+1);

    }
};