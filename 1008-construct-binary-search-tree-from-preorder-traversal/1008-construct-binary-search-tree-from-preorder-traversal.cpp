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
     TreeNode* rec(vector<int>& preorder,int& i,long long bound){
         
         if(preorder.size()==i || preorder[i]>=bound)
             return NULL;
         TreeNode* root=new TreeNode(preorder[i++]);
         
        
         root->left=rec(preorder,i,root->val);
         
        root->right= rec(preorder,i,bound);
         return root;
     }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return rec(preorder,i,INT_MAX);
    }
};