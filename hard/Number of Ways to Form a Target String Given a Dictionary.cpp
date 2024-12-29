class Solution {
public:
    vector<vector<int>>dp,cnt;
    int MOD=1e9 + 7;
    long long helper(int in,int c,string &t,vector<string>&a)
    {
        if(in>=t.size())return 1;
        if(c>=a[0].size())return 0;
        if(dp[in][c]!=-1)return dp[in][c];
        long long op1=helper(in,c+1,t,a)%MOD;
        long long op2=((cnt[c][t[in]-'a']%MOD)*(helper(in+1,c+1,t,a)%MOD))%MOD;
        return dp[in][c]=((op1%MOD)+(op2%MOD))%MOD;
    }

    int numWays(vector<string>& a, string t)
    {
        dp=vector<vector<int>>(t.size(),vector<int>(a[0].size(),-1));
        cnt=vector<vector<int>>(a[0].size(),vector<int>(26,0));
        for(int c=0;c<a[0].size();c++)
        {
            for(int i=0;i<a.size();i++)
            {
                cnt[c][a[i][c]-'a']++;
            }
        }
        int ans=helper(0,0,t,a);
        return  ans;

    }
};
