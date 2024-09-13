class Solution {
public:

    int helper(int l,int r,int p,vector<int>&a,vector<vector<int>>&dp)
    {
        if(l>r)return 0;
        if(dp[l][r]!=-1)return dp[l][r];
        int ans=0;
        if(a[l]<=p)ans=1+helper(l+1,r,p-a[l],a,dp);
        if(l>a.size()-r-1)ans=max(ans,-1+helper(l,r-1,p+a[r],a,dp));
        return dp[l][r]=ans;
    }

    int bagOfTokensScore(vector<int>& tokens, int power) 
    {
        int n=tokens.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        sort(tokens.begin(),tokens.end());
        return helper(0,n-1,power,tokens,dp);
    }
};
