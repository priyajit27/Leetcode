class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        int ans=0;
        sort(tokens.begin(),tokens.end());
        int left=0;int count=0;
        int right=n-1;
      while(left<=right){
          
          if(tokens[left]<=power){
              power-=tokens[left];
              count++;
              ans=max(ans,count);
              left++;
          }
          else if(count>0){
             count--;
              power+=tokens[right];
              right--;
          }
          else 
              break;
      }
        return ans;
    }
};