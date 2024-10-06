class Solution {
public:

    bool checker(vector<int>& m) {
        int first_non_zero = -1;
        for (auto x : m) {
            if (x != 0) {
                if (first_non_zero == -1) {
                    first_non_zero = x;
                } else if (x != first_non_zero) {
                    return false;
                }
            }
        }
        return true;
    }

    int minimumSubstringsInPartition(string s) {
        int n=s.size();
        vector<int> dp(n + 1, INT_MAX); 
        dp[n] = 0;
        for (int in = n - 1; in >= 0; in--) {
            vector<int> m(26,0);
            for (int i = in; i < n; i++) {
                m[s[i]-'a']++; 
                if (checker(m)) dp[in] = min(dp[in], 1 + dp[i + 1]); 
            }
        }
        return dp[0];
    }
};
