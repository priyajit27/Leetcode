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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
         int curr_depth=1;
        
        if(depth==1){
              TreeNode* node=new TreeNode(val,root,NULL);
            return node;
        }
        
         queue<TreeNode*>q;
        
          if(root==NULL){
            return NULL;
        }
        
        
         q.push(root);
        
      
        while(!q.empty()){
            int n=q.size();
           
            while(n--){
               TreeNode* front=q.front() ;
                q.pop();
                if(curr_depth==depth-1){
                    TreeNode* leftt=new TreeNode(val,front->left,NULL);
                    TreeNode* rightt=new TreeNode(val,NULL,front->right);
                        front->left=leftt;
                    front->right=rightt;
                }
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);
                // v1.push_back(front->val);
            } 
            // v.push_back(v1);
            curr_depth++;
        }
        return root;
    }
};