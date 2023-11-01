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
    int freq=0;
    int maxm=INT_MIN;
    int val=0;
    void inorder(TreeNode* root){
        if(!root)return;
        inorder(root->left);
        if(val==root->val){
            freq++;
            // maxm=max(maxm,freq);
        }
        else{
            freq=1;
            val=root->val;
        }
        if(maxm<freq){
            maxm=freq;
            ans={root->val};
        }
        else if(maxm==freq){
             ans.push_back(root->val);
        }
        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;
    }
};