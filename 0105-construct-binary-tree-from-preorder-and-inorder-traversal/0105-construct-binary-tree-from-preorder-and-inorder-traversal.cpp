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
    int prestart=0;
    unordered_map<int,int>mp;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return build(preorder,inorder,0,inorder.size()-1);
    }
        
    TreeNode* build(vector<int>& preorder,vector<int>& inorder,int instart,int inend) {
        if(instart>inend)
            return NULL;
       
        TreeNode* root=new TreeNode(preorder[prestart++]);
        // if(instart==inend)
        //     return root;
        int inroot=mp[root->val];
        root->left=build(preorder,inorder,instart,inroot-1);  
        root->right=build(preorder,inorder,inroot+1,inend);  
        return root;
        }
};