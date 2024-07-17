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
    bool mp[1001]={};
    void rec(TreeNode* &root, vector<TreeNode*>& ans,bool flag){
        if(!root)return;
        rec(root->left,ans,mp[root->val]);
        rec(root->right,ans,mp[root->val]);
        if(!mp[root->val] && flag)ans.push_back(root);
        if(mp[root->val])root=NULL;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
         vector<TreeNode*>ans;
        for(auto i:to_delete)
            mp[i]=true;
        rec(root,ans,true);
        return ans;
    }
};