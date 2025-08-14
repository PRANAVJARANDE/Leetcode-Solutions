class Solution {
public:
    string largestGoodInteger(string s) 
    {
        int ans=-1;
        for(int i=0;i<s.size()-2;i++)
        {
            if(s[i]==s[i+1] && s[i+1]==s[i+2])ans=max(ans,s[i]-'0');
        }
        if(ans==-1)return "";
        return string(3,ans+'0');
        
    }
};
