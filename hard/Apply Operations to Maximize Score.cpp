class Solution {
public:

    long long mod_pow(long long a,long long b, long long m) { 
        long long res=1;
        while(b>0){
            if(b&1){
                res=(res*a)%m;
            }
            a=(a*a)%m;
            b=b>>1;
        }
        return res;
    }

    vector<int> sieve()
    {
        int n=1e5 +2;
        vector<bool>isprime(n,1);
        vector<int>sc(n,0);
        for(int i=2;i<n;i++)
        {
            if(isprime[i]==1)
            {
                sc[i]++;
                for(int j=i+i;j<n;j+=i)
                {
                    isprime[j]=0;
                    sc[j]++;
                }
            }
        }
        return sc;
    }
    long long MOD=1e9 + 7;
    int maximumScore(vector<int>& nums, int k)
    {
        int n=nums.size();
        vector<int>sc=sieve();
        vector<int>v1(n);
        for(int i=0;i<n;i++)v1[i]=sc[nums[i]];
        
        vector<int>nmax(n,0);
        stack<int>s1;
        for(int i=n-1;i>=0;i--)
        {
            while(!s1.empty() && v1[s1.top()]<=v1[i])
            {
                s1.pop();
            }
            if(s1.empty())nmax[i]=n;
            else nmax[i]=s1.top();
            s1.push(i);
        }

        vector<int>pmax(n,0);
        stack<int>s2;
        for(int i=0;i<n;i++)
        {
            while(!s2.empty() && v1[s2.top()]<v1[i])
            {
                s2.pop();
            }
            if(s2.empty())pmax[i]=-1;
            else pmax[i]=s2.top();
            s2.push(i);
        }

        vector<vector<int>>v2(n,vector<int>(2,0));
        for(int i=0;i<n;i++)
        {
            v2[i][0]=nums[i];
            v2[i][1]=i;
        }
        sort(v2.begin(),v2.end());
        

        long long ans=1;
        for(int i=n-1;i>=0;i--)
        {
            long long val=v2[i][0];
            long long in=v2[i][1];
            
            long long st=in-pmax[in];
            long long en=nmax[in]-in;
            long long mv=min((long long)k,st*en);

            long long tm=mod_pow(val,mv,MOD)%MOD;
            ans= ((ans%MOD) * (tm%MOD))%MOD;
            k-=mv;
            if(k==0)break;
        }

        int res=ans;
        return res;
    }
};
