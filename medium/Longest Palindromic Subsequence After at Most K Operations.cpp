class Solution {
public:
    int getcost(char a, char b) {
        int diff = abs(a - b);
        return min(diff, 26 - diff);
    }

    int longestPalindromicSubsequence(string s, int k) {
        int n = s.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1, 0)));
        for (int i = 0; i < n; i++) {
            for (int c = 0; c <= k; c++) {
                dp[i][i][c] = 1;
            }
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                for (int c = 0; c <= k; c++) {
                    if (s[i] == s[j]) {
                        dp[i][j][c] = 2 + dp[i + 1][j - 1][c];
                    } else {
                        int cost = getcost(s[i], s[j]);
                        if (cost <= c) {
                            dp[i][j][c] = max(dp[i][j][c], 2 + dp[i + 1][j - 1][c - cost]);
                        }
                        dp[i][j][c] = max({dp[i][j][c], dp[i + 1][j][c], dp[i][j - 1][c]});
                    }
                }
            }
        }

        return dp[0][n - 1][k];
    }
};
