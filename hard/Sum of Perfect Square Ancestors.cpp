#define ll long long
class Solution {
public:
    static const ll mx = 1e6 + 1;
    static vector<ll> v1;

    static void initSieve() {
        if (!v1.empty()) return;
        v1.assign(mx, 1);
        for (ll i = 2; i < mx; i++) {
            if (v1[i] == 1) {
                v1[i] = i;
                if (i * i < mx) {
                    for (ll j = i * i; j < mx; j += i) {
                        if (v1[j] == 1) v1[j] = i;
                    }
                }
            }
        }
    }

    ll getans(ll n) {
        ll ans = 1;
        while (n > 1) {
            ll rem = v1[n];
            ll cnt = 0;
            while (n % rem == 0) {
                n /= rem;
                cnt++;
            }
            if (cnt % 2) ans *= rem;
        }
        return ans;
    }

    ll helper(ll in, ll par, vector<ll>& m, vector<vector<ll>>& adj, vector<int>& nums) {
        ll temp = getans(nums[in]);
        ll ans = m[temp];
        m[temp]++;
        for (auto x : adj[in]) {
            if (x != par) ans += helper(x, in, m, adj, nums);
        }
        m[temp]--;
        return ans;
    }

    ll sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums) {
        initSieve();
        vector<vector<ll>> adj(n);
        for (auto& x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<ll> m(mx, 0);
        return helper(0, -1, m, adj, nums);
    }
};

vector<ll> Solution::v1;
