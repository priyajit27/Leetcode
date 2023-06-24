class Solution {
public:
    int largestRectangleArea(vector<int>& histo) {
          stack<int>st;
          int area=0;
        int n=histo.size();
        
        int leftsmall[n];int rightsmall[n];
        for(int i=0;i<n;i++){
            
            while(!st.empty() && histo[st.top()]>=histo[i]){
                st.pop();
            }
            if(st.empty())
                leftsmall[i]=0;
            else
                leftsmall[i]=st.top()+1;
            st.push(i);
        }
        
        while(!st.empty())
            st.pop();
        
        for(int i=n-1;i>=0;i--){
             while(!st.empty() && histo[st.top()]>=histo[i]){
                 st.pop();
            }
             if(st.empty())
                rightsmall[i]=n-1;
            else
                rightsmall[i]=st.top()-1;
            st.push(i);
        }
        
        for(int i=0;i<n;i++){
            area=max(area,histo[i]*(rightsmall[i]-leftsmall[i]+1));
        }
        
          
//         Optimal approach
        // for(int i=0;i<=n;i++){
        //     while(!st.empty() && (i==n || histo[st.top()]>=histo[i])){
        //         int width;
        //         int height=histo[st.top()];
        //         st.pop();
        //         if(st.empty())
        //             width=i;
        //         else
        //             width=i-st.top()-1;
        //          area=max(area,height*width);
        //     }
        //     st.push(i);
        // }
        return area;
    }
};