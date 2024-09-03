class Solution {
public:
    int getLucky(string s, int k) {
       string ss;
        for(int i=0;i<s.length();i++){
            ss+=to_string(s[i]-'a'+1);
        }
        int sum=0;
         for(int i=0;i<ss.length();i++){
            sum=sum+(ss[i]-'0');
        }
        cout<<sum<<endl;
        int ans=0;
        k--;
        while(k){
            int num=sum;
            sum=0;
            while(num){
                int a=num%10;
                num/=10;
                sum+=a;
            }
            k--;
        }
        return sum;
    }
};