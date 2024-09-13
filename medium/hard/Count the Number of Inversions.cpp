class Solution {
public:
    const int MOD = 1000000007;

    int helper(int in,int cs,int n,vector<int>&req,vector<vector<int>>&dp)
    {
        if(in>=n)return 1;
        
        if(dp[in][cs]!=-1)return dp[in][cs];
        

        int ans=0;
        if(req[in]==-1)
        {
            for(int i=0;i<=in;i++)
            {
                if(cs+in-i<=400)
                {
                    ans=((ans%MOD)+ (helper(in+1,cs+in-i,n,req,dp)%MOD))%MOD;
                }
            }
        }
        else
        {
            for(int i=0;i<=in;i++)
            {
                if(cs+in-i==req[in])
                {
                    ans=((ans%MOD)+ (helper(in+1,cs+in-i,n,req,dp)%MOD))%MOD;
                }
            }
        }

        
        return dp[in][cs]=ans%MOD;
    }



    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        vector<int> req(n,-1);
        for(auto x:requirements)
        {
            req[x[0]]=x[1];
        }   
        vector<vector<int>>dp(n,vector<int>(401,-1));
        int ans=helper(0,0,n,req,dp);
        return ans;
    }
};
