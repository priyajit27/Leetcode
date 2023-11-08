class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        
        int x=abs(fx-sx);
        int y=abs(fy-sy);
        if(x==0 && y==0){
            if(t==1)
                return false;
        }
        // if(x<=t && y<=t)
        //     return true;
        // return false;
        
        int minm=max(x,y);
        if(minm>t)return false;
        return true;
    }
};