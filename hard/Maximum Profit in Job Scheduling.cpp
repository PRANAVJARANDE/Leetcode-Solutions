class Solution {
public:
    int n;
    int helper(int in,vector<vector<int>>&v1,vector<int>&dp,vector<int>& s)
    {
        if(in>=n)
            return 0;

        if(dp[in]!=-1)
            return dp[in];

        int op1=helper(in+1,v1,dp,s);
        int index=lower_bound(s.begin(),s.end(),v1[in][1])-s.begin();
        int op2=v1[in][2]+helper(index,v1,dp,s);
        return dp[in]=max(op1,op2);
    }

    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& pro) 
    {
        vector<vector<int>> v1;
        n=s.size();
        vector<int>dp(n,-1);
        for(int i=0;i<n;i++)
        {
            v1.push_back({s[i],e[i],pro[i]});
        }
        sort(v1.begin(),v1.end());
        sort(s.begin(),s.end());
        return helper(0,v1,dp,s);
    }
};
