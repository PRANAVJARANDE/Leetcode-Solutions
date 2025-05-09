#define ll long long
class Solution 
{
    const int MOD=1e9+7;
    vector<ll>fact,inv,invFact;
    void precompute(int n) 
    {
        fact=vector<ll>(n+1,1);
        inv=vector<ll>(n+1,1);
        invFact=vector<ll>(n+1,1);
        for(int i=1;i<=n;i++)
        {
            fact[i]=((fact[i-1]%MOD)*(i%MOD))%MOD;
            if(i>=2)inv[i]=MOD-(MOD/i)*inv[MOD%i]%MOD;
            invFact[i]=((invFact[i-1]%MOD)*(inv[i]%MOD))%MOD;
        }
    }

    int ts;
    int n;
    vector<vector<vector<int>>>dp;
    int dfs(int in,int sum,int len,string&s) 
    {
        if(2*sum>ts || len>(n/2)) return 0;
        if(in==n) return(2*sum==ts && len==(n/2))?1:0;
        if(dp[in][sum][len] != -1) return dp[in][sum][len];
        int d=s[in]-'0';
        int op1=dfs(in+1,sum+d,len+1,s); 
        int op2=dfs(in+1,sum,len,s);             
        return dp[in][sum][len] =(op1+op2)%MOD;
    }

public:
    int countBalancedPermutations(string s) {
        n=s.size();
        precompute(n);
        ts=0;
        vector<int> v1(10);
        for(auto x:s)
        {
            int dig=x-'0';
            ts+=dig;
            v1[dig]++;
        }
        if(ts%2)return 0;
        dp.assign(n + 1, vector<vector<int>>((ts/2) + 1, vector<int>((n/2) + 1, -1)));
        int waysToSplit = dfs(0, 0, 0,s);

        ll res = waysToSplit;
        res = res * fact[n/2] % MOD * fact[n - (n/2)] % MOD;
        for (int i : v1)
            res = res * invFact[i] % MOD;

        return res;
    }
};
