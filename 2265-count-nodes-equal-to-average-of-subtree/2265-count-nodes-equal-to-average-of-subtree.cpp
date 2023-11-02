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
    // int counts(TreeNode* root){
    //     if(!root)return 0;
    //     int lh=counts(root->left);
    //     int rh=counts(root->right);
    //     return 1+lh+rh;
    // }
    // int summation(TreeNode* root){
    //     if(!root)return 0;
    //     return root->val+summation(root->left)+summation(root->right);
    // }
    int ans=0;
    pair<int,int>postorder(TreeNode* root){
        if(!root)return {0,0};
        pair<int,int>left=postorder(root->left);
         pair<int,int>right=postorder(root->right);
        
        int nodesum=left.first+right.first+root->val;
        int nodecount=left.second+right.second+1;
        
        if(nodesum/nodecount==root->val)
            ans++;
        
        return {nodesum,nodecount};
    }
    int averageOfSubtree(TreeNode* root) {
//         int ans=0;
//          queue<TreeNode*>q;
//         q.push(root);
//         while(!q.empty()){
//             int sum=0;
//             int count=0;
//             TreeNode* node=q.front();
//             q.pop();
            
//         sum=summation(node);
//         count=counts(node);
            
            
//             if(sum/count==node->val)ans++;
            
//             if(root->left)
//            q.push(root->left) ;
//              if(root->right)
//             q.push(root->right);
//         }
//         return ans;
        
        postorder(root);
        return ans;
    }
};