class Solution {
public:

    int n;
    int helper1(int i,int j,vector<vector<int>>&a,vector<vector<int>>&dp)
    {
        if(i<0 || j<0 || i>=n || j>=n)return INT_MIN;
        if(i==j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int op1=a[i][j]+helper1(i+1,j+1,a,dp);
        int op2=a[i][j]+helper1(i,j+1,a,dp);
        int op3=a[i][j]+helper1(i-1,j+1,a,dp);
        return dp[i][j]=max(op1,max(op2,op3));
    }

    int helper2(int i,int j,vector<vector<int>>&a,vector<vector<int>>&dp)
    {
        if(i<0 || j<0 || i>=n || j>=n)return INT_MIN;
        if(i==j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int op1=a[i][j]+helper2(i+1,j-1,a,dp);
        int op2=a[i][j]+helper2(i+1,j,a,dp);
        int op3=a[i][j]+helper2(i+1,j+1,a,dp);
        return dp[i][j]=max(op1,max(op2,op3));
    }

    int maxCollectedFruits(vector<vector<int>>& a) 
    {
        n=a.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=a[i][i];
            a[i][i]=0;
        }
        vector<vector<int>>dp1(n,vector<int>(n,-1));
        vector<vector<int>>dp2(n,vector<int>(n,-1));
        ans+=helper1(n-1,0,a,dp1);
        ans+=helper2(0,n-1,a,dp2);
        return ans;
    }
};
