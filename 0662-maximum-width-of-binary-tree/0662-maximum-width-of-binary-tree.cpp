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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        int ans=0;
        
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        
        
        while(!q.empty()){
            int x=q.size();
            // TreeNode* node=q.front().first;
                 // int currmin=q.front().second;
            int left;
            int right;
            for(int i=0;i<x;i++){
                long long curr_id=q.front().second;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0)
                    left=curr_id;
                if(i==x-1)
                    right=curr_id;
                if(node->left)
                    q.push({node->left,2*curr_id+1});
                 if(node->right)
                    q.push({node->right,2*curr_id+2});
            }
            ans=max(ans,right-left+1);
        }
        
        return ans;
    }
};