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
      void inorder(TreeNode* root,vector<int>& v){
        if(root==NULL)
            return ;
        if(root->left)
       inorder(root->left,v);
        v.push_back(root->val);
        if(root->right)
        inorder(root->right,v);
    }
    int kthSmallest(TreeNode* root, int k) {
          vector<int>v;
        inorder(root,v);
        priority_queue<int>q;
        for(int i=0;i<v.size();i++)
            q.push(v[i]);
        int n=v.size()-k;
        while(n--){
            q.pop();
        }
        return q.top();
    }
};