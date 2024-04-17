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
           char ch=root->val+'a';
       if(!root->left && !root->right) {
            res.push_back(ch+s);
               // res.push_back(s);
           // s.pop_back();
           return;
       }
        // s+=to_string(root->val);
       if(root->left)  rec(root->left,ch+s);
        if(root->right)   rec(root->right,ch+s);
        // s.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
          string s="";
        // string ans="";
        rec(root,s);
        sort(res.begin(),res.end());
        return res[0];
    }
};