/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p1 , p2;

        roottonode(root,p,p1);
        roottonode(root,q,p2);

        TreeNode* lca = nullptr;
        int i=0;

        while(i < p1.size() && i < p2.size() && p1[i] == p2[i]){
            lca = p1[i];
            i++;
        }

        return lca;

    }
private:

    bool roottonode(TreeNode *root , TreeNode *n , vector<TreeNode*> &a){
        if(!root) return false;
        a.push_back(root);
        if(root->val == n->val) return true;
        if(roottonode(root->left,n,a) || (roottonode(root->right,n,a))){
            return true;
        }
        a.pop_back();
        return false;
    }


};