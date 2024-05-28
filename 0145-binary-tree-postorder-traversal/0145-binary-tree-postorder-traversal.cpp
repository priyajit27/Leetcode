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
    vector<int> postorderTraversal(TreeNode* root) {
    //     if(root==NULL)
    //         return {};
    //     if(root!=NULL){
    //             postorderTraversal(root->left) ;
    //              postorderTraversal(root->right) ;
    //          v.push_back(root->val);
    //     }
    //     return v;
        
        
          // using stack
         if(root==NULL)
            return {};
        stack<TreeNode*>s1;
        stack<TreeNode*>s2;
        s1.push(root);
        while(!s1.empty()){
             root=s1.top();
            s1.pop();
            s2.push(root);
        
            if(root->left)
               s1.push(root->left); 
            if(root->right)
               s1.push(root->right); 
        }
        while(!s2.empty()){
            TreeNode* node=s2.top();
            v.push_back(node->val);
            s2.pop();
        }
        return v;
        
        //   if(root==NULL)
        //     return v;
        //   stack<TreeNode*>st;
        // while(root!=NULL || !st.empty()){
        //     if(root!=NULL){
        //         st.push(root);
        //         root=root->left;
        //     }
        //     else{
        //         TreeNode* temp=st.top()->right;
        //         if(temp==NULL){
        //             temp=st.top();
        //             st.pop();
        //             v.push_back(temp->val);
        //             while(!st.empty() && temp==st.top()->right){
        //                 temp=st.top();
        //                 st.pop();
        //                  v.push_back(temp->val);
        //             }
        //         }
        //         else
        //             root=temp;
        //     }
        // }
        // return v;
    }
};