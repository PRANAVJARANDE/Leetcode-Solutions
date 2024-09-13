class Solution {
public:
    int n;
    bool helper(int i,vector<int>&a,vector<int>&dp)
    {
        if(i>=n)return 1;
        if(dp[i]!=-1)return dp[i];
        bool op1=0,op2=0,op3=0;
        if(i+1<n && a[i]==a[i+1])
        {
            op1=helper(i+2,a,dp);   
        }
        if(i+2<n && a[i]==a[i+1] && a[i]==a[i+2])
        {
            op2=helper(i+3,a,dp);
        }
        if(i+2<n && a[i]+1==a[i+1] && a[i+1]+1==a[i+2])
        {
            op2=helper(i+3,a,dp);
        }
        return dp[i]=op1 || op2 || op3;
    }

    bool validPartition(vector<int>& nums) {
        n=nums.size();
        vector<int>dp(n,-1);
        return helper(0,nums,dp);
    }
};
