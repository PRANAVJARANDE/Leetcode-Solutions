class Solution {
public:

long long mod_pow(long long base, long long exponent, int mod) {
    long long result = 1;
    base = base % mod;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exponent /= 2;
    }
    return result;
}

long long factorial_mod(long long n, long long m) 
{
    long long result = 1;
    for (long long i = 1; i <= n; i++) {
        result = (result * i) % m;
    }
    return result;
}

long long ncr_mod(long long n, long long r, long long m) {
    if (r > n) {
        return 0;  
    }

    long long numerator = factorial_mod(n, m);
    long long denominator = (factorial_mod(r, m) * factorial_mod(n - r, m)) % m;

    long long inverse_denominator = 1;
    long long base = denominator;
    long long exponent = m - 2; 

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            inverse_denominator = (inverse_denominator * base) % m;
        }
        base = (base * base) % m;
        exponent /= 2;
    }

    return (numerator * inverse_denominator) % m;
}

        
    int countKSubsequencesWithMaxBeauty(string s, int k) 
    {
            long long modd=1000000007;
            unordered_map<char,int> f;
            for(char x: s)
                f[x]++;
            
            if(f.size()<k)
                return 0;
            
            unordered_map<int,int> m;
            for(auto x: f)
                m[x.second]++;

            
            vector<vector<int>> v1;
            for(auto x: m)
            {
                    v1.push_back({x.first,x.second});
            }
            sort(v1.begin(),v1.end(),greater<vector<int>>());
            
            long long ans=1;
            for(auto x: v1)
            {
                    int f1=x[0];
                    int f2=x[1];
                    
                    if(f2<=k)
                    {
                        ans=((ans%modd)*(mod_pow(f1,f2,modd)%modd))%modd;
                    }
                    else
                    {
                        ans=((ans%modd)*(mod_pow(f1,k,modd)%modd))%modd;
                        ans=((ans%modd)*(ncr_mod(f2,k,modd))%modd)%modd;
                        break;
                    }
                    k=k-f2;
            }
            return ans;
    }
};
