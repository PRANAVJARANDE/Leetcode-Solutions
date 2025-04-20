class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<long long>>dp(n,vector<long long>(k,0));
        vector<long long>ans(k,0);
        int in=0;
        for(auto x:nums)
        {
            if(in>0)
            {
                for(int i=0;i<k;i++)
                {
                    dp[in][(1ll*i*x)%k]+=dp[in-1][i];
                    ans[(1ll*i*x)%k]+=dp[in-1][i];
                }
            }
            dp[in][x%k]++;
            ans[x%k]++;
            in++;
        }
        return ans;
    }
};
