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
//        vector<int>v;
//       void inorder(TreeNode* root,vector<int>& v){
//         if(root==NULL)
//             return ;
//         if(root->left)
//        inorder(root->left,v);
//         v.push_back(root->val);
//         if(root->right)
//         inorder(root->right,v);
//     }
    
//      TreeNode* ksmallest(TreeNode* root,int k){
//         if(root==NULL)
//             return NULL;
//         if(root->left)
//        inorder(root->left,v);
//         v.push_back(root->val);
//         if(root->right)
//         inorder(root->right,v);
//     }
    void smallest(TreeNode* root, int& k,int& ans){
        if(root==NULL)
            return ;
        smallest(root->left,k,ans);
        k--;
        if(k==0){
            ans=root->val;
            return;
        }
        smallest(root->right,k,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        //   vector<int>v;
        // inorder(root,v);

//         Naive
//         int a=0;
//         for(int i=0;i<k;i++){
//             a=v[i];
//         }
//         return a;
        
//         2nd approach
        // priority_queue<int>q;
        // for(int i=0;i<v.size();i++)
        //     q.push(v[i]);
        // int n=v.size()-k;
        // while(n--){
        //     q.pop();
        // }
        // return q.top();
        
        
//         N solution
        int ans=0;
         smallest(root,k,ans);
       return ans;
    }
};