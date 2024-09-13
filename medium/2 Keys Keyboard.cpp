class Solution {
public:

    int helper(int n,int in,int cpy,vector<vector<int>>&dp)
    {
        if(in>n)
            return INT_MAX/2;
        
        if(in==n)
            return 0;

        if(dp[in][cpy]!=-1)
            return dp[in][cpy];

        //copy
        int op1=INT_MAX/2;
        if(in!=cpy)
        {
            op1=helper(n,in,in,dp);
        }
        //paste
        int op2=INT_MAX/2;
        if(cpy!=0)
        {
            op2=helper(n,in+cpy,cpy,dp);
        }
        return dp[in][cpy]=1+min(op1,op2);
    }

    int minSteps(int n) 
    {
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return helper(n,1,0,dp);
    }
};
