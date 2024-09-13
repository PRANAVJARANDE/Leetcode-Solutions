class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans=0;
        for(auto s: details)
        {
            int age=(s[11]-'0')*10 +(s[12]-'0');
            if(age>60)ans++;
        }
        return ans;
    }
};
