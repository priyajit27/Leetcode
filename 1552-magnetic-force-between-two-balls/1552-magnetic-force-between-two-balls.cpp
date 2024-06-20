class Solution {
public:
    bool isPossible(vector<int> &a,int mid,int ball){
    int coordinate=a[0];
    int count=1;

    for(int i=1;i<a.size();i++){
      if((a[i]-coordinate)>=mid){
          count++;
           if(count==ball)
         return true;
          coordinate=a[i];
      }
    }
    //  if(count>=cow)
    //      return true;

       return false;
}
    int maxDistance(vector<int>& positions, int m) {
//         similar like agressive cows
       int n=positions.size();
    sort(positions.begin(),positions.end());
    int low=0;
    int high=positions[n-1];
     int res=0;
    while(low<=high){
        int mid=(low+high)/2;

        if(isPossible(positions,mid,m)){
              res=mid;
              low=mid+1;
        }
        else
        high=mid-1;

    }
     return res;
    }
};