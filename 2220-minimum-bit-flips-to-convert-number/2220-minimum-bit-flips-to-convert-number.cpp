class Solution {
public:
    int minBitFlips(int start, int goal) {
         int count=0;
        if(goal==start)
            return count;
        
    if(start> goal){
            while(start){
                if((start&1) !=  (goal&1))
                    count++;
                start=start>>1;
                 goal= goal>>1;
            }
        }
        
        else{
               while( goal){
                 if((start&1) !=  (goal&1))
                    count++;
                start=start>>1;
                 goal= goal>>1;
            }
        }
        
        return count;
    }
};