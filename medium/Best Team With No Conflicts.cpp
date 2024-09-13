class Solution {
public:

    int helper(vector<pair<int,int>>&v1,int in,int msi,vector<vector<int>>&dp)
    {
        if(in<0)
            return 0;

        if(dp[in][msi]!=-1)
            return dp[in][msi];

        if(v1[msi].second<v1[in].second)
        {
            return dp[in][msi]= helper(v1,in-1,msi,dp);
        }
        int take=v1[in].second+helper(v1,in-1,in,dp);
        int nottake=helper(v1,in-1,msi,dp);
        return dp[in][msi]= max(take,nottake);
    }


    int bestTeamScore(vector<int>& scores, vector<int>& ages) 
    {
        vector<pair<int,int>> v1;
        int n=ages.size();
        for(int i=0;i<n;i++)
        {
            v1.push_back({ages[i],scores[i]});
        }
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        sort(v1.begin(),v1.end());
        v1.push_back({INT_MAX,INT_MAX});
        return helper(v1,n-1,n,dp);
    }
};
