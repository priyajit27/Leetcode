/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "";
        string ans="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node==NULL) ans.append("#,");
           else ans.append(to_string(node->val)+',');
            if(node){
                  q.push(node->left);
                  q.push(node->right);
            }
            // q.push(node->left);
            // q.push(node->right);
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)
            return NULL;
        
        stringstream s(data);
//         class object makes
        string str;
//         new string
        getline(s,str,',');
//         it will be before ,
        // str will be the new string 
        
         TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            
            getline(s,str,',');
            if(str=="#")
                node->left=NULL;
            else{
                TreeNode* leftnode= new TreeNode(stoi(str));
                node->left=leftnode;
                q.push(leftnode);
            }
            
            
             getline(s,str,',');
            if(str=="#")
                node->right=NULL;
            else{
                  TreeNode* rightnode= new TreeNode(stoi(str));
                node->right=rightnode;
                q.push(rightnode);
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));