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
     vector<int> leaf1(TreeNode* root,vector<int>&a){
                if(root==NULL)
                a.push_back({});
         if(root->left==NULL && root->right==NULL){
               a.push_back(root->val);
        }
          if (root->left)
      leaf1(root->left,a);
          if (root->right)
       leaf1(root->right,a);
       return a;
     }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
          vector<int>a;
          vector<int>b;
         a= leaf1(root1,a);
         b= leaf1(root2,b);
         if(a.size()!=b.size())
         return false;
        for(int i=0;i<a.size();i++ ){
            if(a[i]!=b[i]){
             return false;
            }
        }
         return true;
    }
};