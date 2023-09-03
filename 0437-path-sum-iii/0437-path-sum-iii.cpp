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
     vector<vector<int>>res;
     void rec(TreeNode* root,vector<int>& path,int target,int &count){
        if(!root)return;
        path.push_back(root->val);
         rec(root->left,path,target,count);
          rec(root->right,path,target,count);
         int n=path.size();
         long long sum=0;
         for(int i=n-1;i>=0;i--){
             sum+=path[i];
             if(sum==target)
                 count++;
         }
        path.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
           vector<int>path;
        if(!root)return 0;
        int count=0;
        rec(root,path,targetSum,count);
        return count;
    }
};