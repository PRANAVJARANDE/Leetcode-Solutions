class Solution {
public:
    
    int n;
    int helper(int in,int prev,vector<int>&a,vector<vector<int>>&dp)
    {
        if(in>=n)
        {
            if(in==n)return max(a[in-1],a[prev]);
            return a[prev];
        }
        if(dp[in][prev]!=-1)return dp[in][prev];
        
        int v1=in;
        int v2=in-1;
        int v3=prev;
        
        int op1=max(a[v1],a[v2])+helper(in+2,v3,a,dp);
        int op2=max(a[v1],a[v3])+helper(in+2,v2,a,dp);
        int op3=max(a[v2],a[v3])+helper(in+2,v1,a,dp);
        int ans=min(op2,min(op1,op3));
        return dp[in][prev]=ans;  
    }
    
    int minCost(vector<int>& a) 
    {
        n=a.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans=helper(2,0,a,dp);
        return ans;
    }
};
