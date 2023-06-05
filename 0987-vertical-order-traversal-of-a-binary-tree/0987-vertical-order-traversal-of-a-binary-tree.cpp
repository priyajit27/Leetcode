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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
            vector<vector<int>>ans;
//         vertical level node
       map<int,map<int,multiset<int>>>mp;
        
//         node  vertical level   
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto i=q.front();
            q.pop();
            TreeNode* temp=i.first;
          int vertical=i.second.first;
          int level=i.second.second;
           mp[vertical][level].insert(temp->val);
            if(temp->left){
                q.push({temp->left,{vertical-1,level+1}});
            }
             if(temp->right){
                q.push({temp->right,{vertical+1,level+1}});
            }
        }
        
        
        for (auto p: mp) {
        vector < int > col;
        for (auto q: p.second) {
      col.insert(col.end(), q.second.begin(), q.second.end());
    }
    ans.push_back(col);
  }
  return ans;
    }
};