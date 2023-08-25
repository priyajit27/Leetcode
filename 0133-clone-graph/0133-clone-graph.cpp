/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
       map<int,Node*>mp;
    Node* rec(Node* ans,Node* node){
        ans->val=node->val;
        for(auto i:node->neighbors){
            if(mp.find(i->val)!=mp.end()){
                ans->neighbors.push_back(mp[i->val]);
            }
            else{
                 Node* new1=new Node(i->val);
                mp[i->val]=new1;
                  ans->neighbors.push_back(new1); 
                rec(new1,i);
            }
        }
        return ans;
    }
    Node* cloneGraph(Node* node) {
        if(!node)return NULL;
        Node* ans=new Node();
        mp[1]=ans;
        rec(ans,node);
        return ans;
    }
};