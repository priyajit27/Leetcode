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
      vector<int>v;
    vector<int> inorderTraversal(TreeNode* root) {
       // if(root==NULL)
       //      return {};
       //  if(root!=NULL){
       //          inorderTraversal(root->left) ;
       //          v.push_back(root->val);
       //          inorderTraversal(root->right) ;
       //  }
       //  return v;
        
        
        // using stack
         if(root==NULL)
            return {};
        TreeNode* node=root;
        stack<TreeNode*>st;
        while(true){
            if(node){
                st.push(node);
                node=node->left;
            }
            else{
                if(st.empty()==true)break;
               node= st.top();
                st.pop();
                v.push_back(node->val);
                node=node->right;
            }
        }
        
        return v;
    }
};