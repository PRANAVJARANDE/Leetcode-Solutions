class Solution {
public:

    int helper(int in,int tg,int cnt,string&s,vector<vector<vector<int>>>&dp)
    {
        if(in>=(int)s.size())return cnt;
        if(dp[in][tg][cnt]!=-1)return dp[in][tg][cnt];
        int ans=0;
        if(tg==1)
        {
            for(int i=0;i<=(s[in]-'0');i++)
            {
                int ntg=0;
                if(i==(s[in]-'0'))ntg=1;
                int res=helper(in+1,ntg,cnt+(i==1),s,dp);
                ans+=res;
            }
        }
        else
        {
            for(int i=0;i<=9;i++)
            {
                int res=helper(in+1,0,cnt+(i==1),s,dp);
                ans+=res;
            }
        }
        return dp[in][tg][cnt]=ans;
    }

    int countDigitOne(int n) 
    {
        string s=to_string(n);
        int d=s.size();
        vector<vector<vector<int>>>dp(20,vector<vector<int>>(2,vector<int>(20,-1)));
        return helper(0,1,0,s,dp);
    }
};
