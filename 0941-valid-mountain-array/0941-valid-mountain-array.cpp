class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size();
        if(n<3)
            return false;
        // int mamx=arr[0];
        int k=-1;
        int flag=0;
        if(arr[0]>arr[1])return false;
        for(int i=0;i<n-1;i++){
            if(arr[i]<arr[i+1]){
                flag=1;
                continue;
            }
            else if(arr[i]==arr[i+1])
                return false;
             else if(arr[i]>arr[i+1]){
               k=i;
                 break;
            }
        }
        if(k==-1)return false;
        
          for(int i=k;i<n-1;i++){
            if(arr[i]>arr[i+1]){
                flag=0;
                continue;
            }
            // else if(arr[i]==arr[i+1])
            //     return false;
              else if(arr[i]<=arr[i+1])
                  return false;
        }
        
        if(flag==0)
        return true;
        else
        return false;
        
    }
};