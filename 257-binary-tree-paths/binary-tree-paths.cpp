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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string str;
        helper(root,ans,str);
        return ans;
    }
private:

    void helper(TreeNode *root , vector<string> &arr , string &str){
        if(!root) return;
        
        int len = str.size();
        str += to_string(root->val);

        if(!root->left && !root->right){
            arr.push_back(str);
            str.resize(len);
            return;
        }
        else{
            str += "->";
            helper(root->left,arr,str);
            helper(root->right,arr,str);
        }
        
        str.resize(len);
        
    }
};