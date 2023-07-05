class Solution {
public:
     int check(string& s,int k){
         vector<int>v(26,0);
         int n=s.length();
         if(s.size()==0)
        return 0;
        long long ans=0;
        int left=0;
        int count=0;
        for(int i=0;i<n;i++){
            if(v[s[i]-'a']==0)
            count++;
            v[s[i]-'a']++;
            
        while(count>k){
            v[s[left]-'a']--;
            if(v[s[left]-'a']==0)
            count--;
            left++;
        }
            ans+=i-left+1;
        }
        
        return ans;
  }
    int numberOfSubstrings(string s) {
        
        // Count number of substrings having k distinct gfg solution same
           // TC N^2    sc O(N)
//         int k=3;
//         int n=s.length();
//         long long ans=0;
//         int cnt[26];
//         for(int i=0;i<n;i++){
//             memset(cnt,0,sizeof(cnt));
//              int dist_count = 0;
               
//              for(int j=i;j<n;j++){
//                  if(cnt[s[j]-'a']==0){
//                       dist_count++;
//                  }
//                 cnt[s[j]-'a']++; 
//                  if(dist_count==k)
//                   ans++;
//                   if(dist_count>k)
//                   break;
//              }
//         }
//         return ans;
        
         // O(N) O(1) as the array is of size 3 only
        int k=3;
         return check(s,k)-check(s,k-1);
        
    }
};