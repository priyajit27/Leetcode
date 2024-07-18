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
    int ans=0;
    vector<int>rec(TreeNode* root, int d){
        if(!root)return {};
        if(!root->left && !root->right)return {1};
        auto l=rec(root->left,d);
         auto r=rec(root->right,d);
        vector<int>a;
        for(auto i:l){
            for(auto j:r){
                if(i+j<=d)ans++;
            }
        }
        for(auto i:l){
            if(i+1<=d)a.push_back(i+1);
        }
         for(auto i:r){
            if(i+1<=d)a.push_back(i+1);
        }
        
        return a;
    }
    int countPairs(TreeNode* root, int distance) {
        rec(root,distance);
        return ans;
    }
};