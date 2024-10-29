class Solution {
public:

    int n,m;
    int helper(int i,int j,vector<vector<int>>&a,vector<vector<int>>&dp)
    {
        int op1=0,op2=0,op3=0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(j+1<m && i-1>=0 && a[i][j]<a[i-1][j+1])op1=1+helper(i-1,j+1,a,dp);
        if(j+1<m && a[i][j]<a[i][j+1])op2=1+helper(i,j+1,a,dp);
        if(j+1<m && i+1<n && a[i][j]<a[i+1][j+1])op3=1+helper(i+1,j+1,a,dp);
        return dp[i][j]=max(op1,max(op2,op3));
    }

    int maxMoves(vector<vector<int>>& a) {
        n=a.size();
        m=a[0].size();
        vector<vector<int>>dp(n,vector<int>(m+1,-1));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,helper(i,0,a,dp));
        }
        return ans;
    }
};
