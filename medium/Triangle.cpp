//Optimized space complexity
class Solution {
public:

    int minimumTotal(vector<vector<int>>& a) 
    {
        int n=a.size();
        int ans=a[0][0];
        for(int i=1;i<n;i++)
        {
            ans=INT_MAX;
            for(int j=0;j<a[i].size();j++)
            {
                int op1=INT_MAX,op2=INT_MAX;
                if(j-1>=0)op1=a[i][j]+a[i-1][j-1];
                if(j!=a[i].size()-1)op2=a[i][j]+a[i-1][j];
                a[i][j]=min(op1,op2);
                ans=min(ans,a[i][j]);
            }
        }
        return ans;
    }
};

// Not optimized space complexity
class Solution {
public:

    int helper(vector<vector<int>>&nums,int i,int j,vector<vector<int>>& dp)    
    {
        if(i>=nums.size())
            return 0;

        if(dp[i][j]!=-1)
            return dp[i][j];

        return dp[i][j]=nums[i][j]+min(helper(nums,i+1,j,dp),helper(nums,i+1,j+1,dp));
    }

    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(triangle[n-1].size(),-1));
        return helper(triangle,0,0,dp);
    }
};
