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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        vector<int> pre_p ,pre_q;

        preorder(p,pre_p);
        preorder(q,pre_q);

        if(pre_p.size() != pre_q.size()) return 0;

        for(int i=0 ; i<pre_p.size() ;i++){
            if(pre_p[i] != pre_q[i])
                return 0;
        }

        return 1;

    }
private:

    void preorder(TreeNode *a , vector<int>& in_a){
        if(!a){
            in_a.push_back(INT_MIN);
            return;
        }

        in_a.push_back(a->val);
        preorder(a->left,in_a);
        preorder(a->right,in_a);
    }

};