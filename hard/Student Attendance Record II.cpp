class Solution {
public:

    int n;
    int MOD=1e9 + 7;
    long long helper(int in,int a,int l,vector<vector<vector<long long>>>&dp)
    {
        if(in>=n)return 1;
        if(dp[in][a][l]!=-1)return dp[in][a][l];

        long long op1=0,op2=0,op3=0;
        if(a==0)
        {
            op2=helper(in+1,a+1,0,dp);
        }
        if(l==2)
        {
            op3=0;
        }
        else
        {
            op3=helper(in+1,a,l+1,dp);
        }
        op1=helper(in+1,a,0,dp);
        return dp[in][a][l]=((op1%MOD)+(op2%MOD)+(op3%MOD))%MOD;
    }

    int checkRecord(int d) 
    {
        n=d;
        vector<vector<vector<long long>>>dp(n,vector<vector<long long>>(2,vector<long long>(3,-1)));
        return helper(0,0,0,dp);
    }
};
