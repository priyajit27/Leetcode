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
      vector<string>res;
       void rec(TreeNode* root,string s){
        if(!root)return;
       if(!root->left && !root->right) {
             // s.push_back(root->val);
             s+=to_string(root->val);
               res.push_back(s);
           s.pop_back();
           return;
       }
        s+=to_string(root->val);
         rec(root->left,s+"->");
          rec(root->right,s+"->");
        s.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
           string s="";
        if(!root)return {};
        rec(root,s);
        return res;
    }
};