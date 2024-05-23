class Solution {
public:
   
    int merge(vector<int>& arr, int low, int mid, int high){
        int count=0;
        int j=mid+1;
        for(int i=low;i<=mid;i++){
            while(j<=high && arr[i]>2*1LL*arr[j])
                j++;
            
            count+=j-(mid+1);
        }
//          while(i<=mid && j<=high){
        
//     }
        
          vector<int>v;
    // int count=0;
    int l=low;
    int r=mid+1;

    while(l<=mid && r<=high){
          if(arr[l]<=arr[r]){
              v.push_back(arr[l]);
              l++;
          }
          else{
            //   count+=mid-l+1;
                 v.push_back(arr[r]);
               r++;
          }
    }

    while(l<=mid){
       v.push_back(arr[l]);
       l++;
    }

      while(r<=high){
         v.push_back(arr[r]);
       r++;
      }
       
         // transfering all elements from temporary to arr //
       for(int i=low;i<=high;i++){
           arr[i]=v[i-low];
       }
        return count;
    }

    int mergeSort(vector<int>& arr, int low, int high){
      int count=0;
     if(low>=high)
     return count;
     int mid=(low+high)/2;
     count+= mergeSort(arr,low,mid);
     count+= mergeSort(arr,mid+1,high);
      count+= merge(arr,low,mid,high);
       return count;
    }



    int reversePairs(vector<int>& arr) {
        return mergeSort(arr,0,arr.size()-1);
    }
};