class Solution {
public:

    int n;
    long long INF=-1E15;
    long long helper(int in,int k,bool b,vector<int>&nums,vector<vector<vector<long long>>>&dp)
    {
        if(k==0)return 0;
        if(in>=n)return INF;
        if(dp[in][k][b]!=INF)return dp[in][k][b];

        //Skip element
        long long op1=INF;
        if(b)op1=helper(in+1,k,1,nums,dp);
        
        long long tm;
        if(k%2)tm=k;
        else tm=-k;
        long long op2=tm*nums[in] + helper(in+1,k-1,1,nums,dp);
        long long op3=tm*nums[in] + helper(in+1,k,0,nums,dp);
        return dp[in][k][b]=max(op1,max(op3,op2));
    }


    long long maximumStrength(vector<int>& nums, int k) {
        n=nums.size();
        vector<vector<vector<long long>>>dp(n,vector<vector<long long>>(k+1,vector<long long>(2,INF)));
        long long ans=helper(0,k,1,nums,dp);
        return ans;
    }
};
