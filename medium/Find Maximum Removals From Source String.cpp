class Solution {
public:
    int n, m;
    vector<bool> toRemove;

    int helper(int in, int i2, string& s, string& t, vector<vector<int>>& dp) {
        if (in >= n)
        {
            if(i2<m)return INT_MIN;
            return 0;
        }
        if (dp[in][i2] != -1) return dp[in][i2];

        int ni2 = i2;
        if (i2<m && s[in] == t[i2]) ni2++;

        if (toRemove[in]) {
            int op1 = 1 + helper(in + 1, i2, s, t, dp);
            int op2 = helper(in + 1, ni2, s, t, dp);
            return dp[in][i2] = max(op1, op2);
        } else {
            return dp[in][i2] = helper(in + 1, ni2, s, t, dp);
        }
    }

    int maxRemovals(string s, string p, vector<int>& a) {
        n = s.size();
        m = p.size();
        toRemove.assign(n, false);
        for (int index : a) toRemove[index] = true;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return helper(0, 0, s, p, dp);
    }
};
