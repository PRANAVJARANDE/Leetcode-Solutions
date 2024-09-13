class Solution {
public:
    int n;
    bool helper(string s,int in,int op,vector<vector<int>>&dp)
    {
        if(op<0)
            return 0;

        if(in>=n)
        {
            if(op==0)
                return 1;
            return 0;
        }

        if(dp[in][op]!=-1)
            return dp[in][op];

        if(s[in]=='(')
            return  dp[in][op]=helper(s,in+1,op+1,dp);
        
        if(s[in]==')')
            return  dp[in][op]=helper(s,in+1,op-1,dp);
        
        //*== ""
        int op1=helper(s,in+1,op,dp);
        int op2=helper(s,in+1,op+1,dp);
        int op3=helper(s,in+1,op-1,dp);
        return  dp[in][op]=op1 || op2 || op3;
    }



    bool checkValidString(string s) 
    {
        n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return helper(s,0,0,dp);
    }
};
