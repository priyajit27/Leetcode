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
    vector<int>ans;
    TreeNode* bst(int l,int r){
        if(l>r)return NULL;
        int mid=(l+r)/2;
        TreeNode* root=new TreeNode(ans[mid]);
        // root->val=ans[mid];
       root->left= bst(l,mid-1);
       root->right= bst(mid+1,r);
        return root;
    }
    void inorder(TreeNode* root){
        if(!root)return;
        inorder(root->left);
        ans.push_back(root->val);
         inorder(root->right);
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return bst(0,ans.size()-1);
    }
};