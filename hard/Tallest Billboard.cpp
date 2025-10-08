class Solution {
public:

    int n;
    int helper(int in,int s1,vector<int>&a,vector<vector<int>>&dp)
    {
        if(in>=a.size())
        {
            if(s1==0)return 0;
            return -1E8;
        }
        if(dp[in][s1+5000]!=-1)return dp[in][s1+5000];
        int op1=helper(in+1,s1,a,dp);
        int op2=a[in]+helper(in+1,s1+a[in],a,dp);
        int op3=helper(in+1,s1-a[in],a,dp);
        return dp[in][s1+5000]=max(op1,max(op2,op3));
    }

    int tallestBillboard(vector<int>& a) 
    {
        n=a.size();
        vector<vector<int>>dp(n,vector<int>(10002,-1));
        int ans=helper(0,0,a,dp);
        return ans;
    }
};
