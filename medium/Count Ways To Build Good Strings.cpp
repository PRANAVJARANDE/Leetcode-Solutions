class Solution {
public: 

    int MOD=1e9 + 7;
    vector<int>dp;
    long long helper(int in,int l,int r,int c1,int c2)
    {
        if(in>r)return 0;
        if(dp[in]!=-1)return dp[in];
        long long ta=0;
        if(in>=l)ta++;
        long long op1=helper(in+c1,l,r,c1,c2)%MOD;
        long long op2=helper(in+c2,l,r,c1,c2)%MOD;
        return dp[in]=(ta+op1+op2)%MOD;
    }

    int countGoodStrings(int l, int r, int c1, int c2) 
    {
        dp=vector<int>(r+1,-1);
        int ans=helper(0,l,r,c1,c2);
        return ans;
    }
};
