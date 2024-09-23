class Solution {
public:
    int n;
    map<string,int> m;
    int helper(int in,string s,vector<int>&dp)
    {
        if(in>=n)return 0;
        if(dp[in]!=-1)return dp[in];
        int op1=INT_MAX;
        for(int i=in;i<n;i++)
        {
            if(m[s.substr(in,i-in+1)])
            {
                op1=min(op1,helper(i+1,s,dp));
            }
        }
        int op2=1+helper(in+1,s,dp);
        return dp[in]=min(op1,op2);
    }

    int minExtraChar(string s, vector<string>& dict) {
        for(auto x: dict)m[x]++;
        n=s.size();
        vector<int>dp(n,-1);
        return helper(0,s,dp);
    }
};
