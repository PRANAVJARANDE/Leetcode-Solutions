class Solution {
public:
    
    int n,m;
    int helper(int r,int c1,int c2,vector<vector<int>>&arr,vector<vector<vector<int>>>&dp)
    {
        if(r>=n)
            return 0;
        
        if(c1<0 || c2<0 || c1>=m || c2>=m)
            return 0;

        if(dp[r][c1][c2]!=-1)return dp[r][c1][c2];
        
        int ans=0;
        if(c1==c2)ans+=arr[r][c1];
        else ans+=arr[r][c1]+arr[r][c2];

        int op1=helper(r+1,c1+1,c2+1,arr,dp);
        int op2=helper(r+1,c1+1,c2-1,arr,dp);
        int op3=helper(r+1,c1+1,c2,arr,dp);
        int op4=helper(r+1,c1-1,c2+1,arr,dp);
        int op5=helper(r+1,c1-1,c2-1,arr,dp);
        int op6=helper(r+1,c1-1,c2,arr,dp);
        int op7=helper(r+1,c1,c2+1,arr,dp);
        int op8=helper(r+1,c1,c2-1,arr,dp);
        int op9=helper(r+1,c1,c2,arr,dp);

        ans+=max(max(max(op5,op6),max(op1,op2)),max(max(op7,max(op8,op9)),max(op3,op4)));
        return dp[r][c1][c2]=ans;
    }

    int cherryPickup(vector<vector<int>>&arr) 
    {
        n=arr.size();
        m=arr[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return helper(0,0,m-1,arr,dp);
    }
};
