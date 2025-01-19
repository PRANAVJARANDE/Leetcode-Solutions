#define ll long long
class Solution {
public:
    const int MOD = 1E9 + 7;
    vector<ll> fact, invFact;
    
    void precomputeFactorials(int maxN) {
        fact.resize(maxN + 1);
        invFact.resize(maxN + 1);
        
        fact[0] = 1;
        for (int i = 1; i <= maxN; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        
        invFact[maxN] = modPow(fact[maxN], MOD - 2, MOD);
        for (int i = maxN - 1; i >= 0; i--) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        }
    }
    
    ll modPow(ll base, ll exp, ll mod) {
        ll result = 1;
        while (exp > 0) {
            if (exp & 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }
    
    ll nCr(int n, int r) {
        if (r > n) return 0;
        return (fact[n] * invFact[r] % MOD) * invFact[n - r] % MOD;
    }
    
    int minMaxSums(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        precomputeFactorials(n); 
        
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            int fr = n - i - 1;  
            int bk = i;          
            
            ll contribution = 0;
            for (int j = 0; j < k; j++) {
                ll op1 = nCr(fr, j);
                ll op2 = nCr(bk, j);
                contribution = (contribution + (op1 + op2) % MOD) % MOD;
            }
            
            ans = (ans + (nums[i] * contribution) % MOD) % MOD;
        }
        
        return ans;
    }
};
