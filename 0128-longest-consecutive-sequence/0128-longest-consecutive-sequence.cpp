class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>s;
         for(auto i:nums){
             s.insert(i);
         }
        int len=0;
        for(int num:nums){
            if(!s.count(num-1)){
               int currnum=num;
               int currlen=1;
                while(s.count(currnum+1)){
                    currnum+=1;
                    currlen++;
                    
                }
                len=max(len,currlen);
            }
        }
        return len;
    }
};