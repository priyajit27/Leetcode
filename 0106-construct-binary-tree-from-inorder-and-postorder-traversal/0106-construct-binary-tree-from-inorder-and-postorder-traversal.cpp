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
         unordered_map<int,int>mp;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return build(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1);
    }  
    TreeNode* build(vector<int>& postorder,int poststart,int postend,vector<int>& inorder,int instart,int inend) {
        // int postend=postorder.size()-1;
        if(instart>inend )
            return NULL;
        TreeNode* root=new TreeNode(postorder[postend]);
        if(instart==inend)
            return root;
        int inroot=mp[root->val];
        int left=inroot-instart;
        root->left=build(postorder,poststart,poststart+left-1,inorder,instart,inroot-1);  
        root->right=build(postorder,poststart+left,postend-1,inorder,inroot+1,inend);  
        return root;
        }

};