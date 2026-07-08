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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(root->val == key){
            if(!root->left && !root->right){
                delete root;
                return nullptr;
            }
            if((root->left == NULL) != (root->right == NULL)){
                TreeNode* temp = root->left? root->left:root->right;
                delete root;
                return temp;
            }
            if(root->left && root->right){
                int max = maxfinder(root->left);
                // cout << max;
                root->val = max;
                root->left = deleteNode(root->left , max);
            }

        }
        if(root->val > key) 
            root->left = deleteNode(root->left , key);
        else
            root->right = deleteNode(root->right , key);
        
        return root;
       
    }
private:
    int maxfinder(TreeNode *root){
        if(!root) return -1;
        while(root->right)
            root = root->right;
        return root->val;
    }

};