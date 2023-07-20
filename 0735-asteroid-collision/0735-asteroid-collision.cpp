class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
//         if it is negative then compare if positive then push back
        int n=asteroids.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            if(asteroids[i]>0)st.push(asteroids[i]);
            else{
                
                while(!st.empty() && st.top()>0 && st.top()<abs(asteroids[i]) ){
                    st.pop();
                }
                
                if(!st.empty() && st.top()==abs(asteroids[i]))
                    st.pop();
                
                else if(st.empty() || st.top()<0)
                    st.push(asteroids[i]);
            }
        }
         vector<int>ans(st.size());
       for(int i=st.size()-1;i>=0;i--){
           ans[i]=st.top();
           st.pop();
       }
        return ans;
    }
};