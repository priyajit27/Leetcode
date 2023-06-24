class Solution {
public:
    int largestRectangleArea(vector<int>& histo) {
          stack<int>st;
          int area=0;
        int n=histo.size();
          
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || histo[st.top()]>=histo[i])){
                int width;
                int height=histo[st.top()];
                st.pop();
                if(st.empty())
                    width=i;
                else
                    width=i-st.top()-1;
                 area=max(area,height*width);
            }
            st.push(i);
        }
        return area;
    }
};