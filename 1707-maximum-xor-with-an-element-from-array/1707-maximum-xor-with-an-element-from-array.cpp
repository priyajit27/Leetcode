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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
          int q=queries.size();
          int n=nums.size();
        sort(nums.begin(),nums.end());
          vector<int>ans(q,-1); 
        
        vector<pair<int,pair<int,int>>>offline;
        
        int index=0;
        for(auto i:queries){
            offline.push_back({i[1],{i[0],index++}});
        }
        
        sort(offline.begin(),offline.end());
        
        int j=0;
          Trie trie;
        
        for(int i=0;i<q;i++){
            int ai=offline[i].first;
            int xi=offline[i].second.first;
            int index=offline[i].second.second;
            
            while(j<n && nums[j]<=ai){
                trie.insert(nums[j]);
                j++;
            }
            
            if(j!=0)
            ans[index]=trie.maxi(xi);
            
        }
        
        
        return ans;
    }
};