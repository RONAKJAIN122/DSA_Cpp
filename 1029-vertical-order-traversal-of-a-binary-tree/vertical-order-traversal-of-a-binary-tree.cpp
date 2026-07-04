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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //make a queue & map
        queue<pair<TreeNode*, pair<int,int>>> q;
        map<int,vector<pair<int,int>>> mp;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            mp[curr.second.second].push_back({curr.second.first , curr.first->val});
            if(curr.first->left)
                q.push({curr.first->left,
                        {curr.second.first + 1,
                        curr.second.second - 1}});
            if(curr.first->right)
                q.push({curr.first->right,
                        {curr.second.first + 1,
                        curr.second.second + 1}});
        }
        //just make ans by sorting

        vector<vector<int>> ans;

        for(auto x : mp){
            sort(x.second.begin() , x.second.end());
            vector<int> temp;
            for(auto y : x.second){
                temp.push_back(y.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};