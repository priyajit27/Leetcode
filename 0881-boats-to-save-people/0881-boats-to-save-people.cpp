class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int s=0,e=people.size()-1;
        int count=0;
        while(s<=e){
            if(people[s]+people[e]<=limit){
                s++;e--;
            }
            else
                e--;
            count++;
        }
        return count;
    }
};