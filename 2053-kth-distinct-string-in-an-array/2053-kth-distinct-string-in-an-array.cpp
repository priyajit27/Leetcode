class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        vector<string>a;
       for(int i=0;i<arr.size();i++){
           string s=arr[i];
            bool ok=true;
           for(int j=0;j<arr.size();j++){
               // bool ok=true;
               if(i!=j && s==arr[j])
                   ok=false;
           }
           if(ok)
               a.push_back(s);
       }
        
        if(a.size()<k)
        return "";
        
       return a[k-1];
       
    }
};