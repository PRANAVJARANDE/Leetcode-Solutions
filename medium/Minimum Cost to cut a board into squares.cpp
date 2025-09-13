class Solution 
{
  public:
    
    int n,m;
    int helper(int i,int j,vector<int>&x,vector<int>&y,vector<vector<int>>&dp)
    {
        if(i>=n && j>=m)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int op1=INT_MAX;
        if(i<n)op1=((j+1)*x[i])+helper(i+1,j,x,y,dp);
        int op2=INT_MAX;
        if(j<m)op2=((i+1)*y[j])+helper(i,j+1,x,y,dp);
        return dp[i][j]=min(op1,op2);
    }
  
    int minCost(int nn, int mm, vector<int>& x, vector<int>& y) 
    {
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        reverse(x.begin(),x.end());
        reverse(y.begin(),y.end());
        m=nn-1;
        n=mm-1;
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return helper(0,0,x,y,dp);
    }
};
