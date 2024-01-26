class Solution {
public:

    int MOD=1e9+7;
    int m,n;
    int helper(int x,int y,int k,vector<vector<vector<long long>>>&dp)
    {
        if(k<0)
            return 0;
        
        if(x<0 || y<0 || x>=m || y>=n)
            return 1;

        if(dp[x][y][k]!=-1)
            return dp[x][y][k];
        
        long long op1=helper(x-1,y,k-1,dp)%MOD;
        long long op2=helper(x+1,y,k-1,dp)%MOD;
        long long op3=helper(x,y-1,k-1,dp)%MOD;
        long long op4=helper(x,y+1,k-1,dp)%MOD;
        return dp[x][y][k]=( (op1)%MOD + (op2)%MOD + (op3)%MOD +(op4)%MOD )%MOD;
    }


    int findPaths(int mm, int nn, int k, int x, int y) 
    {
        m=mm,n=nn;
        vector<vector<vector<long long>>>dp(m,vector<vector<long long>>(n,vector<long long>(k+1,-1)));
        return helper(x,y,k,dp);
    }
};
