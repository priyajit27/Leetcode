//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&nums, int n){   
        int sum=0;
        int maxi=0;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            sum+=nums[i];
           if(sum==0)
           maxi=i+1;
           
           else{
                 if(mp.find(sum)!=mp.end()){
                maxi=max(i-mp[sum],maxi);
           }
           else
                 mp[sum]=i;
           }
        }
        return maxi;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends