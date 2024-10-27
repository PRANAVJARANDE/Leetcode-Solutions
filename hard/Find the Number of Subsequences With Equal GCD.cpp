class Solution {
public:
    const int MOD = 1e9 + 7;
    int n;
    vector<vector<vector<long long>>> dp;

    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long long helper(int in, int gc1, int gc2, vector<int>& nums) {
        if (in >= n) {
            return gc1 == gc2 ? 1 : 0;
        }
        if (dp[in][gc1][gc2] != -1) {
            return dp[in][gc1][gc2];
        }
        long long op1 = helper(in + 1, gc1, gc2, nums)%MOD;
        long long op2 = helper(in + 1, gcd(gc1, nums[in]), gc2, nums)%MOD;
        long long op3 = helper(in + 1, gc1, gcd(gc2, nums[in]), nums)%MOD;
        return dp[in][gc1][gc2] = (op1 % MOD + op2 % MOD + op3 % MOD) % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        dp = vector<vector<vector<long long>>>(n, vector<vector<long long>>(201, vector<long long>(201, -1)));
        return helper(0, 0, 0, nums)-1;
    }
};
