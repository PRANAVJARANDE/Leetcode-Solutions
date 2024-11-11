class Solution {
public:
    int n;
    int MOD = 1000000007;
    int sumOfGoodSubsequences(vector<int>& nums) {
        n = nums.size();
        int ans = 0;
        map<int, pair<int, int>> dp;
        
        for (int i = n - 1; i >= 0; i--) {
            int ta = (1 + dp[nums[i] + 1].first + dp[nums[i] - 1].first) % MOD;
            dp[nums[i]].first = (dp[nums[i]].first + ta) % MOD;
            
            dp[nums[i]].second = (dp[nums[i]].second + 
                                  (1LL * nums[i] * ta % MOD + 
                                   dp[nums[i] + 1].second + 
                                   dp[nums[i] - 1].second) % MOD) % MOD;
        }
        
        for (auto x : dp) {
            ans = (ans + x.second.second) % MOD;
        }
        
        return ans;
    }
};
