class Solution {
public:

    int n,m;
    int helper(int i,int j,string&s,string&t,vector<vector<int>>&dp)
    {
        if(j>=m)return 1;
        if(i>=n)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int op1=0;
        if(s[i]==t[j])op1=helper(i+1,j+1,s,t,dp);
        int op2=helper(i+1,j,s,t,dp);
        return dp[i][j]=op1+op2;
    }

    int numDistinct(string s, string t) {
        n=s.size();
        m=t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(0,0,s,t,dp);
    }
};
