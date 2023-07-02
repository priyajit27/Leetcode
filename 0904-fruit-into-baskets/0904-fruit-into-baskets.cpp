class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int last_fruit=-1;
        int second_last_fruit=-1;
        int last_fruit_count=0;
        int maxm=0;
        int currentmax=0;
        for(auto fruit:fruits){
            if(fruit==last_fruit || fruit==second_last_fruit)
                currentmax++;
            else
                currentmax=last_fruit_count+1;
            
             if(fruit==last_fruit){
                last_fruit_count++; 
             }
            else{
               last_fruit_count=1;
                 second_last_fruit=last_fruit;
                last_fruit=fruit;
            }
            
            maxm=max(maxm,currentmax);
        }
        return maxm;
    }
};