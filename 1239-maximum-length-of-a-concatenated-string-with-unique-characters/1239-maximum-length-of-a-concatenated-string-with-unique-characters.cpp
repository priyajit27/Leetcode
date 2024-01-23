class Solution {
public:
     int ans=0;
   bool isUnique(string s){
       set<char>st;
       for(auto x:s)st.insert(x);
       if(s.size()==st.size())return true;
       return false;
   }
   void backtrack(vector<string>&arr,string temp,int start){
        if(!isUnique(temp) )return ;
        ans=max(ans,(int)temp.size());
         for(int i=start;i<arr.size();i++)
          backtrack(arr,temp+arr[i],i+1);
           
   }
    int maxLength(vector<string>& arr) {
     string s="";
        backtrack(arr,s,0);
        return ans;
    }
};