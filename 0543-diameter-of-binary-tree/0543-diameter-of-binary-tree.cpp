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
    int height(TreeNode* root){
      if(root==NULL)
      return 0;
      return  max(height(root->left),height(root->right))+1;
    }
     int findmax(TreeNode* root,int& maxi){
      if(root==NULL)
      return 0;
      int lh=findmax(root->left,maxi) ;
      int rh=findmax(root->right,maxi);
         maxi=max(maxi,lh+rh);
         return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
//          if(root==NULL)
//            return 0;
// //         N^2 solution
//        int dl=diameterOfBinaryTree(root->left);
//         int dr=diameterOfBinaryTree(root->right);
    
//     int curr=1+height(root->left)+height(root->right);
//         return max(curr,max(dl,dr));
        
//         N solution
        int maxi=0;
        findmax(root,maxi);
        return maxi;
    }
};