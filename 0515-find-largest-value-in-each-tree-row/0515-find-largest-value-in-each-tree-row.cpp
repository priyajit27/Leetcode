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
    vector<int> largestValues(TreeNode* root) {
           vector<int>ans;
        queue<TreeNode*>q;
        q.push(root);
        
        if(root==NULL){
            return {};
        }
        
        while(!q.empty()){
            int n=q.size();
            vector<int>v1;
            while(n--){
               TreeNode* front=q.front() ;
                q.pop();
                if(front->left!=NULL)
                    q.push(front->left);
                if(front->right!=NULL)
                    q.push(front->right);
                v1.push_back(front->val);
            } 
            int maxm=INT_MIN;
            for(int i=0;i<v1.size();i++){
                maxm=max(maxm,v1[i]);
            }
            ans.push_back(maxm);
        }
        return ans;
    }
};