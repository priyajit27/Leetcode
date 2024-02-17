class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n=heights.size();
        priority_queue<int>pq;   
        int i;
        for( i=0;i<n-1;i++){
           int diff=heights[i+1]-heights[i];
            if(diff>0){
           if(diff<=bricks){
               pq.push(diff);
               bricks-=diff;
           }
                else if(ladders>0){
                    if(!pq.empty() && pq.top()>diff){
                        int t=pq.top();
                        bricks+=t-diff;
                        pq.pop();
                        pq.push(diff);
                        ladders--;
                    }
                    else
                        ladders--;
                }
                else
                    break;
        }
        }
        return i;
    }
};