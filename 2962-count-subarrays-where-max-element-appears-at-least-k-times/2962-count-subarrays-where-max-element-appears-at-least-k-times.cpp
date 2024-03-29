class Solution {
public:
    long long countSubarrays(vector<int>& a, int k) {
        int n=a.size();
        int maxm= *max_element(a.begin(), a.end());
        int i=0;
        int j=0;
        int count=0;
        long long ans=0;
        while(j<n){
            if(a[j]==maxm)
                count++;
          while(count==k){
              if(a[i]==maxm)
                  count--;
              i++;
          }
            ans+=i;
            j++;
        }
        return ans;
    }
};