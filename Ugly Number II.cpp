class Solution {
public:
    int nthUglyNumber(int n) {
        int c2=0,c3=0,c5=0;
        vector<int> dp(n,0);
        dp[0]=1;
        for(int i=1;i<n;i++)
        {
            dp[i]=min(dp[c2]*2,min(dp[c3]*3,dp[c5]*5));
            if(dp[i]==dp[c2]*2)
            {
                c2++;
            }
            if(dp[i]==dp[c3]*3)
            {
                c3++;
            }
            if(dp[i]==dp[c5]*5)
            {
                c5++;
            }
        }
        return dp[n-1];
    }
};
