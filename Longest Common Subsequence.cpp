class Solution {
public:

    int helper(string &a,string &b,vector<vector<int>>&dp,int m,int n)
    {
        if(m==0 || n==0)
        {
            return 0;
        }

        if(dp[m][n]!=-1)
        {
            return dp[m][n];
        }

        if(a[m-1]==b[n-1])
        {
            return dp[m][n]= 1+helper(a,b,dp,m-1,n-1);
        }
        return dp[m][n]=max(helper(a,b,dp,m,n-1),helper(a,b,dp,m-1,n));
    }


    int longestCommonSubsequence(string a, string b) 
    {
        int m=a.size();
        int n=b.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return helper(a,b,dp,m,n);
    }
};
