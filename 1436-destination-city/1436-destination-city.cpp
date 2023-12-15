class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string>s;
        for(auto i:paths)
            s.insert(i[0]);
        
        for(auto path:paths){
            string des=path[1];
            if(s.find(path[1])==s.end())
                return des;
        }
        
        return NULL;
    }
};