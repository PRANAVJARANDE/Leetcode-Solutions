class Solution {
public:
    int m, n;
    int helper(int i, int j, vector<vector<int>>& arr, vector<vector<int>>& dp) 
    {
        if (i >= m || j >= n)
            return INT_MAX;

        if (i == m - 1 && j == n - 1) {
            if (arr[i][j] < 0) {
                return -arr[i][j] + 1;
            }
            return 1;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        int op1 = helper(i + 1, j, arr, dp);
        int op2 = helper(i, j + 1, arr, dp);
        int ans = min(op1, op2) - arr[i][j];
        if (ans <= 0) {
            return dp[i][j] = 1;
        }
        return dp[i][j] = ans;
    }

    int calculateMinimumHP(vector<vector<int>>& arr) {
        m = arr.size();
        n = arr[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(0, 0, arr, dp);
    }
};
