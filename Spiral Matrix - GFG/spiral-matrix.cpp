//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findK(vector<vector<int>> &matrix, int n, int m, int k)
    {
        //   int n=matrix.size();
        // int m=matrix[0].size();
        vector<int>ans;
        int left=0;
        int top=0;
        int right=m-1;
        int bottom=n-1;
        
        while(left<=right && top<=bottom){
            
            for(int i=left;i<=right;i++)
                ans.push_back(matrix[top][i]);
            
            top++;
            
            for(int i=top;i<=bottom;i++)
                ans.push_back(matrix[i][right]);
            
            right--;
            
            if(top<=bottom){
                 for(int i=right;i>=left;i--)
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
            
            if(left<=right){
                  for(int i=bottom;i>=top;i--)
                ans.push_back(matrix[i][left]);
            }
            left++;
            
        }
        int res=0;
        for(int i=0;i<k;i++)
        res=ans[i];
        
        return res;
    }

};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        vector<vector<int>> a(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        Solution obj;

        cout<< obj.findK(a, n, m, k) << "\n";
        
       
    }
}
// } Driver Code Ends