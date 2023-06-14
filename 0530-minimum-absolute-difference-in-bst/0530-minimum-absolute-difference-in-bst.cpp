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
    // vector<int>ans;
    // void inorder(TreeNode* root){
    //     if(root==NULL)
    //         return;
    //     inorder(root->left);
    //     ans.push_back(root->val);
    //     inorder(root->right);
    // }
    
    
     TreeNode* prev=NULL;
      void inorder(TreeNode* root,int& minm){
        if(root==NULL)
            return;
        inorder(root->left,minm);
        if(prev){
            minm=min(abs(prev->val-root->val),minm);
        }
          prev=root;
        inorder(root->right,minm);
    }
    int getMinimumDifference(TreeNode* root) {
        
//         T.C O(N)   S.C O(N)
        // inorder(root);
        // int n=ans.size();
        // int mini=INT_MAX;
        // for(int i=1;i<n;i++){
        //     if(abs(ans[i]-ans[i-1])<mini)
        //         mini=abs(ans[i]-ans[i-1]);
        // }
        // return mini;
        
       
//             T.C O(N)   S.C O(H)
        int minm=INT_MAX;
        inorder(root,minm);
        return minm;
    }
};