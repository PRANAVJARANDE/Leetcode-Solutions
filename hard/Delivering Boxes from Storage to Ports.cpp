class Solution {
public:

    int n;
    int helper(int in,vector<vector<int>>&a,int mb,int mw,vector<int>&dp)
    {
        if(in>=n)return 0;
        if(dp[in]!=-1)return dp[in];
        int wt=0;
        int tadd=1;
        int j=in;
        for(;j<min(n,in+mb);j++)
        {
            wt+=a[j][1];
            if(wt>mw)break;
            if(j==in)tadd++;
            else if(a[j-1][0]!=a[j][0])tadd++;
        }
        int res1=tadd+helper(j,a,mb,mw,dp);
        int nin=j-1;
        while(nin>=in && a[nin][0]==a[j-1][0])
        {
            nin--;
        }
        int res2=INT_MAX;
        if(nin>=in)res2=tadd-1+helper(nin+1,a,mb,mw,dp);
        return dp[in]=min(res1,res2);
    }

    int boxDelivering(vector<vector<int>>& a, int pc, int mb, int mw) 
    {
        n=a.size();
        vector<int>dp(n,-1);
        return helper(0,a,mb,mw,dp);
    }
};
