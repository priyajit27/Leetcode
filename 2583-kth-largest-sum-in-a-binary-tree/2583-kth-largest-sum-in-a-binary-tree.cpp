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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        long long m=1e9+7;
        if(root==NULL)return 0;
        queue<TreeNode*>q;
         priority_queue<long, vector<long>, greater<long>> pq;
        q.push(root);
        vector<long long>ans;
        while(!q.empty()){
             int x=q.size();
            long long sum=0;
            while(x--){
                TreeNode* t=q.front();
                q.pop();
                sum+=t->val;
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            pq.push(sum);
            if(pq.size()>k)
                pq.pop();
        }
        // sort(ans.begin(),ans.end(),greater<int>());
        if(k>pq.size())return -1;
        return pq.top();
    }
};