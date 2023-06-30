class Node{
    public:
    Node* links[2];
    
    bool iscontain(int bit){
        return (links[bit]!= NULL);
    }
  
    void put(int bit,Node * node){
        links[bit]=node;
    }
    
    //to get the next node for traversal
    Node* get(int bit){
        return links[bit];
    }
};
class Trie {
public:
    Node* root;
    Trie() {
        root=new Node();
    }
    
    void insert(int num) {
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i) & 1;
            if(!node->iscontain(bit)){
              node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }

    int maxi(int num){
       Node* node=root;
       int maxm=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i) & 1;
            if(node->iscontain(!bit)){
                maxm=maxm | (1<<i);
               node=node->get(!bit);
            }
            else
            node=node->get(bit);
        }
        return maxm;
    }

};
class Solution {
public:
    int findMaximumXOR(vector<int>& a) {
        Trie trie;
    for(auto i:a){
        trie.insert(i);
    }
int maxxor=0;
     for(auto i:a){
        maxxor=max(trie.maxi(i),maxxor);
    }
    return maxxor;
    }
};