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
         void helper(TreeNode*root,vector<int>&v){
        if(root==NULL)
            return ;
        // if(root!=NULL){
                v.push_back(root->val);
                helper(root->left,v) ;
              helper(root->right,v) ;
        // }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>v;
        helper(root,v);
        return v;
        
//         // using stack
//          if(root==NULL)
//             return {};
//         stack<TreeNode*>st;
//         st.push(root);
//         while(!st.empty()){
//              root=st.top();
//             st.pop();
//            v.push_back(root->val) ;
// //             O(N)
//             if(root->right)
//                st.push(root->right); 
//              if(root->left)
//                st.push(root->left); 
//         }
//         return v;
    }
};