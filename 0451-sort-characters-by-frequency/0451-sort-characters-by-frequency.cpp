class Solution {
public:
    string frequencySort(string s) {
          string s1="";
             unordered_map<char,int> mp;
        for(auto i:s){
            mp[i]++;
        }
        
        priority_queue<pair<int,char>>pq;
        
        for(auto i:mp){
            pq.push({i.second,i.first});
        }
        
        while(!pq.empty()){
            auto i=pq.top();
            int x=i.first;
            char c=i.second;
            pq.pop();
            while(x){
                s1+=c;
                x--;
            }
            
        }
        
        
        return s1;
        
//         SC  O(N)+o(k)+O(k)
//         TC  0(N)+0(Nlogk)+O(klogk)
    }
};