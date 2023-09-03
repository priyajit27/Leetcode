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
     vector<vector<int>>res;
    void rec(TreeNode* root,vector<int>& path,int target){
        if(!root)return;
       if(!root->left && !root->right) {
             path.push_back(root->val);
           if(target==root->val){
               res.push_back(path);
           }
           path.pop_back();
           return;
       }
        path.push_back(root->val);
         rec(root->left,path,target-root->val);
          rec(root->right,path,target-root->val);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        if(!root)return {};
        rec(root,path,targetSum);
        return res;
    }
};