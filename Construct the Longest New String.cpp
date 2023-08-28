class Solution {
public:
    vector<vector<vector<vector<int>>>> dp;
    int helper(int x, int y, int z, int prev) 
    {
        if (dp[x][y][z][prev] != -1) {
            return dp[x][y][z][prev];
        }

        int op = 0;
        if (prev == 1) {
            if (y > 0) {
                op = 2 + helper(x, y - 1, z, 2);
            }
        } else {
            if (x > 0) {
                op = max(op, 2 + helper(x - 1, y, z, 1));
            }
            if (z > 0) {
                op = max(op, 2 + helper(x, y, z - 1, 3));
            }
        }

        return dp[x][y][z][prev] = op;
    }

    int longestString(int x, int y, int z) {
        dp.resize(x + 1, vector<vector<vector<int>>>(y + 1, vector<vector<int>>(z + 1, vector<int>(4, -1))));

        return max({2 + helper(x - 1, y, z, 1),
                    2 + helper(x, y - 1, z, 2),
                    2 + helper(x, y, z - 1, 3)});
    }
};
