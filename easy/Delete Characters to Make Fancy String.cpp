class Solution {
public:
    string makeFancyString(string s) {
        int n=s.size();
        if(n<=2)return s;
        string ans="";
        ans+=s[0];
        ans+=s[1];
        for(int i=2;i<s.size();i++)
        {
            if(s[i]==s[i-1] && s[i]==s[i-2])continue;
            else ans+=s[i];
        }
        return ans;
    }
};
