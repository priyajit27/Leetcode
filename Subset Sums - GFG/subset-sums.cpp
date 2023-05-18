//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
void rec(int index,int sum,vector<int>& ans,int n,vector<int>& arr){
    if(index==n){
        ans.push_back(sum);
        return;
    }
    
    // pick
    rec(index+1,sum+arr[index],ans,n,arr);
    
    // not pick
     rec(index+1,sum,ans,n,arr);
}
    vector<int> subsetSums(vector<int> arr, int N){
         vector<int>ans;
         rec(0,0,ans,N,arr);
         sort(ans.begin(),ans.end());
         return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends