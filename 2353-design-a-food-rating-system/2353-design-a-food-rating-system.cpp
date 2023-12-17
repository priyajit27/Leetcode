class FoodRatings {
public:
    map<string,set<pair<int,string>>>mp;
    map<string,int>rate;
    map<string,string>cus;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            rate[foods[i]]=ratings[i];
             cus[foods[i]]=cuisines[i];
            mp[cuisines[i]].insert({-ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuss=cus[food];
        int old=rate[food];
        rate[food]=newRating;
        mp[cuss].erase({-old,food});
         mp[cuss].insert({- newRating,food});
    }
    
    string highestRated(string cuisine) {
        return mp[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */