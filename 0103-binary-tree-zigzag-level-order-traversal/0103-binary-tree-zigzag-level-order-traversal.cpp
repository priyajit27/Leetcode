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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>>ans;
        if(root==NULL)
            return ans;
        queue<TreeNode*>q;
        q.push(root);
        int i=0;
        while(!q.empty()){
            int x=q.size();
            vector<int>a;
            while(x--){
            TreeNode* p=q.front();
               a.push_back(p->val);
            q.pop();
            if(p->left)
               q.push(p->left);
            if(p->right)
                 q.push(p->right);
            }
            if(i%2)
                reverse(a.begin(),a.end());
            ans.push_back(a);
            i++;
        }
        return ans;
    }
};