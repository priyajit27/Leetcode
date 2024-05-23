class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int num1=INT_MIN;
        int num2=INT_MIN;
        int c1=0;
        int c2=0;
        for(int num:nums){
            if(num==num1){
                c1++;
            }
            else if(num==num2){
                c2++;
            }
            else if(c1==0){
                num1=num;
                c1=1;
            }
            else if(c2==0){
                num2=num;
                c2=1;
            }
            else{
                c1--;
                c2--;
            }            
        }
        vector<int>ans;
        c1=0;
        c2=0;
        for(int num:nums){
            if(num==num1)c1++;
            if(num==num2)c2++;
        }
        int mini=int(n/3)+1;
        if(c1>=mini)
            ans.push_back(num1);
         if(c2>=mini)
            ans.push_back(num2);
        
        return ans;
    }
};