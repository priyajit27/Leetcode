class Solution {
public:
    bool rotateString(string s, string goal) {
        s =s+s;
         if(s.length()!=2*goal.length())
            return false;
        // int a=s.find(goal);
        if(s.find(goal)!=-1)
            return true;
        return false;
    }
};