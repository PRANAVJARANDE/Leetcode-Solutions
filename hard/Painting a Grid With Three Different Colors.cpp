#define ll long long
const int MOD = 1e9 + 7;
class Solution {
public:
    int r, c;
    vector<vector<int>> v1;

    void generate(int n, vector<int>& a) {
        if (a.size() == n) {
            v1.push_back(a);
            return;
        }
        for (int i = 0; i < 3; ++i) {
            if (!a.empty() && a.back() == i) continue;
            a.push_back(i);
            generate(n, a);
            a.pop_back();
        }
    }

    unordered_map<int, unordered_map<int, ll>> dp;

    int hashState(const vector<int>& vec) {
        int hash = 0;
        for (int i = 0; i < vec.size(); ++i) {
            hash = hash * 3 + vec[i];  
        }
        return hash;
    }

    bool isCompatible(const vector<int>& a, const vector<int>& b) {
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == b[i]) return false;
        }
        return true;
    }

    ll helper(int in, const vector<int>& prev) {
        if (in == c) return 1;

        int prevHash = hashState(prev);
        if (dp[in].count(prevHash)) return dp[in][prevHash];

        ll ans = 0;
        for (auto& x : v1) {
            if (isCompatible(prev, x)) {
                ans = (ans + helper(in + 1, x)) % MOD;
            }
        }
        return dp[in][prevHash] = ans;
    }

    int colorTheGrid(int n, int m) {
        r = n;
        c = m;
        v1.clear();
        vector<int> a;
        generate(n, a);

        vector<int> empty(n, -1); 
        return helper(0, empty);
    }
};
