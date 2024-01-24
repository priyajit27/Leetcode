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
    // int ans=0;
    void rec(TreeNode* root,string& s,int& ans){
        if(!root)return;
        
        if(s[root->val-1]=='0')
            s[root->val-1]='1';
        else
            s[root->val-1]='0';
        
        if(!root->left && !root->right){
            if(count(s.begin(),s.end(),'1')<2)ans++;
            cout<<ans<<" ";
            // return;
        }
            
        rec(root->left,s,ans);
        rec(root->right,s,ans);
        
         if(s[root->val-1]=='0')
            s[root->val-1]='1';
        else
            s[root->val-1]='0';
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans=0;
        string s="000000000";
        rec(root,s,ans);
        return ans;
    }
};