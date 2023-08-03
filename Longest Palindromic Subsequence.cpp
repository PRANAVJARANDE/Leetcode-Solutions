class Solution {
public:

    int helper(string &s,int i,int j,vector<vector<int>>&dp)
    {
        if(i>j)
            return 0;

        if(dp[i][j]!=-1)
            return dp[i][j];

        if(i==j)
        {
            return dp[i][j]=1;
        }
        if(s[i]==s[j])
        {
            return dp[i][j]=2+helper(s,i+1,j-1,dp);
        }

        int op1=helper(s,i+1,j,dp);
        int op2=helper(s,i,j-1,dp);
        return dp[i][j]=max(op1,op2);
    }


    int longestPalindromeSubseq(string s) 
    {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return helper(s,0,n-1,dp);
    }
};
