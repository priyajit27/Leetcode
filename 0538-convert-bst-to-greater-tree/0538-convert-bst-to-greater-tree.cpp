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
     void inorder(TreeNode* root, vector<int>& ans){
        if(root==NULL)return;
       inorder(root->left,ans);
        ans.push_back(root->val);
         inorder(root->right,ans);
    }
      void inorderupdate(TreeNode* root, vector<int>& ans,int& i){
            if(root==NULL)return;
       inorderupdate(root->left,ans,i);
        root->val=ans[i++];
         inorderupdate(root->right,ans,i);
    }
    TreeNode* convertBST(TreeNode* root) {
         vector<int>ans;
        inorder(root,ans);
        int n=ans.size();
        for(int i=n-2;i>=0;i--){
               ans[i]+=ans[i+1];
            // cout<<ans[i]<<endl;
        }
            // ans[i]+=ans[i+1];
        int j=0;
        inorderupdate(root,ans,j); 
        return root;
    }
};