class Solution {
public:
    int numberOfSteps(int num) {
        int ans=0;
        while(num){
            if(num%2){
                 num-=1;
                ans++;
            }
            else  if(num%2==0){
                 num/=2;
            ans++;
            }
        }
        return ans;
    }
};