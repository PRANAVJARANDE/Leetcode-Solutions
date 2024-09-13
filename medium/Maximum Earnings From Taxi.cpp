class Solution {
public:
    vector<int>temp;
    int m;
    long long helper(int &n,vector<vector<int>>&nums,int in,vector<long long>&dp)
    {
        if(in>=m)
            return 0;

        if(dp[in]!=-1)
            return dp[in];
        
        int k=lower_bound(temp.begin(),temp.end(),nums[in][1])-temp.begin();
        long long op1=(nums[in][1]-nums[in][0]+nums[in][2])+helper(n,nums,k,dp);
        long long op2=helper(n,nums,in+1,dp);
        return dp[in]=max(op1,op2);
    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(),rides.end());
        m=rides.size();
        for(int i=0;i<m;i++)
        {
            temp.push_back(rides[i][0]);
        }
        vector<long long>dp(m+1,-1);
        return helper(n,rides,0,dp);
    }
};
