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
    int diameterOfBinaryTree(TreeNode* root) {
        return diameterandheightedges(root).first;
    }
private:

    pair<int,int> diameterandheightedges(TreeNode *root){
        if(!root) return {0,-1};
        pair<int,int> ldata = diameterandheightedges(root->left);
        pair<int,int> rdata = diameterandheightedges(root->right);
        
        int curr_dia = ldata.second + rdata.second + 2;
        int dia_temp = max(ldata.first , rdata.first);
        int dia = max(curr_dia,dia_temp);
        int height = max(ldata.second , rdata.second) + 1;

        return {dia,height};
    }
};