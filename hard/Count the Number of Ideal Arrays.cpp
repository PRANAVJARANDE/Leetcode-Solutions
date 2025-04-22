#define ll long long
class Solution {
public:
    static const int MOD = 1e9 + 7;
    vector<int> fact, invFact;
    void prepare(int upTo) 
    {
        fact.resize(upTo);
        invFact.resize(upTo);
        fact[0] = 1;
        for (int i = 1; i < upTo; ++i) {
            fact[i] = (ll)fact[i - 1] * i % MOD;
        }
        invFact[upTo - 1] = modInverse(fact[upTo - 1]);
        for (int i = upTo - 2; i >= 0; --i) {
            invFact[i] = (ll)invFact[i + 1] * (i + 1) % MOD;
        }
    }
    vector<int> getSPF(int maxVal) {
        vector<int> spf(maxVal + 1);
        for (int i = 2; i <= maxVal; ++i) {
            if (!spf[i]) {
                for (int j = i; j <= maxVal; j += i) {
                    if (!spf[j]) spf[j] = i;
                }
            }
        }
        return spf;
    }
    map<int, int> getFactors(int num, const vector<int>& spf) {
        map<int, int> freq;
        while (num > 1) {
            int p = spf[num];
            ++freq[p];
            num /= p;
        }
        return freq;
    }
    ll nCr(int a, int b) {
        if (b > a) return 0;
        return (ll)fact[a] * invFact[b] % MOD * invFact[a - b] % MOD;
    }
    int modInverse(int x) {
        return power(x, MOD - 2);
    }
    int power(int base, int exp) {
        ll res = 1;
        while (exp) {
            if (exp & 1) res = res * base % MOD;
            base = (ll)base * base % MOD;
            exp >>= 1;
        }
        return res;
    }

    int idealArrays(int n, int maxValue) 
    {
        int maxi=n+100;
        prepare(maxi);
        vector<int>spf=getSPF(maxValue);
        ll total=0;
        for(int val = 1; val <= maxValue; ++val) 
        {
            auto factors=getFactors(val,spf);
            ll count=1;
            for (auto x : factors) count = count * nCr(n + x.second - 1, x.second) % MOD;
            total = (total + count) % MOD;
        }
        return total;
    }
};
