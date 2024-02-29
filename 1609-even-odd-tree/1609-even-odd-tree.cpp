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
    bool isEvenOddTree(TreeNode* root) {
         vector<vector<int>>v;
        queue<TreeNode*>q;
        q.push(root);
        
//         if(root==NULL){
//             return v;
//         }
          int level=1;
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
            if(level%2){
                if(v1[0]%2==0)return false;
                for(int i=1;i<v1.size();i++){
                    if(v1[i]%2==0)return false;
                    if(v1[i]-v1[i-1]<=0)return false;
                }
            }
            else{
                   if(v1[0]%2)return false;
                for(int i=1;i<v1.size();i++){
                    if(v1[i]%2)return false;
                    if(v1[i]-v1[i-1]>=0)return false;
                }
            }
            level++;
        }
        return true;
    }
};