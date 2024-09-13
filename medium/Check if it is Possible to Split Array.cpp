class Solution {
public:

    bool helper(vector<int>&nums,int m,int i,int j,vector<int>&psum,vector<vector<int>>&dp)
    {
        if(i>j)
            return 0;

        if(dp[i][j]!=-1)
            return dp[i][j];

         if(i==j)
            return dp[i][j]=1;

        int s;
        if(i==0)
        {
            s=psum[j];
        }
        else
        {
            s=psum[j]-psum[i-1];
        }
        
        if(s<m)
            return dp[i][j]=0;

        bool ans=0;
        for(int k=i;k<j;k++)
        {
            bool b1=helper(nums,m,i,k,psum,dp);
            bool b2=helper(nums,m,k+1,j,psum,dp);
            ans= ans || (b1 && b2);
        }
        return dp[i][j]=ans;
    }


    bool canSplitArray(vector<int>& nums, int m) 
    {
        int n=nums.size();
        if(n==2 || n==1)
        {
            return 1;
        }
        vector<int>psum(n,0);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        psum[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            psum[i]=nums[i]+psum[i-1];
        }
        return helper(nums,m,0,n-1,psum,dp);
    }
};
