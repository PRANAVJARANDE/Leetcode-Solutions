class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& nums) {
        vector<vector<int>>dp=nums;
        int n=nums.size(),ans=INT_MAX;
        if(n==1)
        {
            return nums[0][0];
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<n;j++)
            {
                int op1=dp[i+1][j];
                int op2=(j!=0)? dp[i+1][j-1]:INT_MAX;
                int op3=(j!=n-1)?dp[i+1][j+1]:INT_MAX;
                dp[i][j]=nums[i][j]+min(op1,min(op2,op3));
                if(i==0)
                {
                    ans=min(ans,dp[0][j]);
                }
            }
            
        }
        return ans;
    }
};
