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
    int maxLevelSum(TreeNode* root) {
        
        queue<TreeNode*>q;
        q.push(root);
        
        if(root==NULL){
            return 0;
        }
        int count=0;
        int maxsum=INT_MIN;
        int maxcount=0;
        while(!q.empty()){
            int n=q.size();
              count++;
            // vector<int>v1;
              int sum=0;
            while(n--){
               TreeNode* front=q.front() ;
                sum+=front->val;
                q.pop();
                if(front->left!=NULL)
                    q.push(front->left);
                if(front->right!=NULL)
                    q.push(front->right);
                // v1.push_back(front->val);
                  // count++;
        }
         // // int sum=0;
         //    for(auto i:v1)
         //        sum+=i;
        if(sum>maxsum){
            maxsum=sum;
            maxcount=count;
        }}
        return maxcount;
    }
};