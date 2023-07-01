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
            int height=histo[i];
            int width= rightsmall[i]-leftsmall[i]+1;
            int side=min(height,width);
            area=max(side*side,area);
        }
        return area;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
           int n=matrix.size();
        int m=matrix[0].size();
        
        int maxarea=0;
        vector<int>height(m,0);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(matrix[i][j]=='1') 
                   height[j]++;
                else
                    height[j]=0;
            }
          int area= largestRectangleArea(height);
            maxarea=max(area,maxarea);
        }
        
        return maxarea;
    }
};