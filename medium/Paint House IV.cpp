#define ll long long
class Solution {
public:
    ll helper(int in, int p1, int p2, vector<vector<int>>& cost, vector<vector<vector<ll>>>& dp, int n) {
      
        if (in >= n / 2) return 0;

        if (dp[in][p1][p2] != -1) return dp[in][p1][p2];

        ll ans = 1E15;

        for (int c1 = 0; c1 < 3; c1++) {
            if (c1 != p1) {
                for (int c2 = 0; c2 < 3; c2++) {
                    if (c2 != p2 && c2 != c1) {
                        ll res = cost[in][c1] + cost[n - in - 1][c2] + helper(in + 1, c1, c2, cost, dp, n);
                        ans = min(ans, res);
                    }
                }
            }
        }

        return dp[in][p1][p2] = ans;
    }

    long long minCost(int n, vector<vector<int>>& cost) {
        vector<vector<vector<ll>>> dp(n / 2, vector<vector<ll>>(4, vector<ll>(4, -1)));

        return helper(0, 3, 3, cost, dp, n);
    }
};
