class Solution {
public:
    int totalFruit(vector<int>& fruits) {
//         int last_fruit=-1;
//         int second_last_fruit=-1;
//         int last_fruit_count=0;
//         int maxm=0;
//         int currentmax=0;
//         for(auto fruit:fruits){
//             if(fruit==last_fruit || fruit==second_last_fruit)
//                 currentmax++;
//             else
//                 currentmax=last_fruit_count+1;
            
//              if(fruit==last_fruit){
//                 last_fruit_count++; 
//              }
//             else{
//                last_fruit_count=1;
//                  second_last_fruit=last_fruit;
//                 last_fruit=fruit;
//             }
            
//             maxm=max(maxm,currentmax);
//         }
//         return maxm;
        
                map<int,int>mp;
        int n=fruits.size();
       int i=0,j=0;
       int ans=0;
       while(j<n){
           mp[fruits[j]]++;
           while(mp.size()>2){
           //  if(mp[fruits[i]]==1){
           //     mp.erase(fruits[i]);
           //        // mp[fruits[i]]--;
           // }
           // else{
           mp[fruits[i]]--;
               if(mp[fruits[i]]==0)
                  mp.erase(fruits[i]) ;
           // }
           i++;
           }
           ans=max(j-i+1,ans);
           j++;
       }
       return ans;    
    }
};